import Shader;

import StaticSystemPaths;
import WindowManager;

import std;

Shader::Shader() {
	ID = 0;
}

Shader::Shader(const char* vertexSource, const char* fragmentSource, bool globalOverride) {
	Compile(vertexSource, fragmentSource);
	if (globalOverride) {
		GlobalShader::getInstance()->setShader(this);
	}
	else {
		GlobalShader::getInstance()->trySetShader(this);
	}
}

void Shader::Compile(const char* vertexSource, const char* fragmentSource) {
	// vertex shader
	unsigned int vertexShader = GLAD::glCreateShader(GLAD::GL_VERTEX_SHADER);
	GLAD::glShaderSource(vertexShader, 1, &vertexSource, nullptr);
	GLAD::glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	GLAD::glGetShaderiv(vertexShader, GLAD::GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLAD::glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	unsigned int fragmentShader = GLAD::glCreateShader(GLAD::GL_FRAGMENT_SHADER);
	GLAD::glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
	GLAD::glCompileShader(fragmentShader);
	// check for shader compile errors
	GLAD::glGetShaderiv(fragmentShader, GLAD::GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLAD::glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	ID = GLAD::glCreateProgram();
	GLAD::glAttachShader(ID, vertexShader);
	GLAD::glAttachShader(ID, fragmentShader);
	GLAD::glLinkProgram(ID);
	// check for linking errors
	GLAD::glGetProgramiv(ID, GLAD::GL_LINK_STATUS, &success);
	if (!success) {
		GLAD::glGetProgramInfoLog(ID, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	GLAD::glDeleteShader(vertexShader);
	GLAD::glDeleteShader(fragmentShader);
}

Shader::~Shader() {
	GLAD::glDeleteProgram(ID);
}

void Shader::Use() {
	GLAD::glUseProgram(ID);
}

void Shader::drawObjects(const std::string& windowName, const float& currentTime) {
	WindowManager* manager = WindowManager::getInstance();
	std::shared_ptr<WindowContext::Camera> camera = manager->getWindowCamera(windowName);

	this->Use();

	glm::mat4 view = camera->getViewMatrix();
	glm::mat4 projection = camera->getProjectionMatrix(800.0f / 600.0f);
	int viewLoc = GLAD::glGetUniformLocation(ID, "view");
	int projLoc = GLAD::glGetUniformLocation(ID, "projection");
	GLAD::glUniformMatrix4fv(viewLoc, 1, GLAD::GL_FALSE, glm::value_ptr(view));
	GLAD::glUniformMatrix4fv(projLoc, 1, GLAD::GL_FALSE, glm::value_ptr(projection));

	for (int i = 0; i < textures.size(); i++) {
		textures[i]->bind();
	}

	for (int i = 0; i < renderObjects.size(); i++) {
		renderObjects[i]->draw(ID, currentTime);
	}

	for (int i = 0; i < textures.size(); i++) {
		textures[i]->unbind();
	}
}

std::shared_ptr<RenderObject::RenderObject> Shader::createObject(RenderObject::Data renderObjectData) {
	this->Use();
	renderObjects.push_back(std::make_shared<RenderObject::RenderObject>(renderObjectData));
	return renderObjects.back();
}

std::shared_ptr<RenderObject::Texture> Shader::createTexture(const std::string& imagePath) {
	this->Use();
	textures.push_back(std::make_shared<RenderObject::Texture>(StaticSystemPaths::ExecutionFolder + "\\Textures\\" + imagePath));
	return textures.back();
}

GlobalShader* GlobalShader::getInstance() {
	static GlobalShader instance;
	return &instance;
}

void GlobalShader::trySetShader(Shader* shader) {
	if (shader && shader->ID != 0) {  // Added null check for safety
		this->shader = shader;
	}
}

void GlobalShader::setShader(Shader* shader) {
	this->shader = shader;
}

void GlobalShader::drawShaderObjects(const std::string& windowName, const float& deltaTime) {
	if (shader) {  // Safety check for null pointer
		shader->drawObjects(windowName, deltaTime);
	}
}