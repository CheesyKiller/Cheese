export module RenderObjectShapeKey;

export import RenderObjectKeyframe;

export namespace RenderObject {
	struct ShapeKey {
		std::string name;
		std::vector<Keyframe> keyframes;
	};
}