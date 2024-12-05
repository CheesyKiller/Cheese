export module RenderObjectNode;

import std;
import RenderObjectNodeInput;
import RenderObjectNodeOutput;

export namespace RenderObject {
    struct Node {
        std::string name;
        std::string type;
        std::vector<NodeInput> inputs;
        std::vector<NodeOutput> outputs;
    };
}