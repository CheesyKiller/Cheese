module;

#include <vector>
#include <memory>

export module Shader;

export import ShaderSources;
export import GLAD;
export import RenderObject;

export struct Shader {
	unsigned int ID;
	std::vector<std::shared_ptr<RenderObject>> renderObjects;

	Shader();
	Shader(const char* vertexSource, const char* fragmentSource, bool globalOverride = false);
	~Shader();

	void Compile(const char* vertexSource, const char* fragmentSource);
	void Use();

	void drawObjects() {
		this->Use();
		for (auto& obj : renderObjects) {
			obj->Draw();
		}
	}

	std::shared_ptr<RenderObject> createObject() {
		this->Use();
		renderObjects.push_back(std::make_shared<RenderObject>());
		return renderObjects.back();
	}
};

export struct GlobalShader {
	static GlobalShader* getInstance() {
		static GlobalShader instance;
		return &instance;
	}

	GlobalShader(const GlobalShader&) = delete;
	GlobalShader& operator=(const GlobalShader&) = delete;

	void trySetShader(Shader* shader) {
		if (shader->ID != 0) {
			this->shader = shader;
		}
	}

	void setShader(Shader* shader) {
		this->shader = shader;
	}

	void drawShaderObjects() {
		shader->drawObjects();
	}
	
	Shader* shader;
private:
	GlobalShader() = default;
};