export module RenderObjectNodeInput;

import GLM;
import std;

export namespace RenderObject {
	struct NodeInput {
		std::string name;
		bool isLinked;
		std::variant<float, glm::vec3, glm::vec4> defaultValue;
	};
}