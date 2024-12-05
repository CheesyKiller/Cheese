export module RenderObjectNodeTree;

import std;
import RenderObjectNode;
import RenderObjectNodeLink;

export namespace RenderObject {
	struct NodeTree {
		std::vector<Node> nodes;
		std::vector<NodeLink> links;
	};
}