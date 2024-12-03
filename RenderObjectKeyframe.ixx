export module RenderObjectKeyframe;

export import GLM;

export namespace RenderObject {
	struct Keyframe {
		float frame;
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
}