export module RenderObject;

export struct RenderObject {
	RenderObject();
	~RenderObject();

	void Draw();

private:
	unsigned int VAO, VBO, EBO;

	float vertices[12] = {
	 0.5f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f
	};
	unsigned int indices[6] = {
		0, 1, 3,
		1, 2, 3
	};
};