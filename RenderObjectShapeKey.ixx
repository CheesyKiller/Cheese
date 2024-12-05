export module RenderObjectShapeKey;

import std;
import RenderObjectKeyframe;

export namespace RenderObject {
	struct ShapeKey {
		std::string name;
		std::vector<Keyframe> keyframes;
	};
}