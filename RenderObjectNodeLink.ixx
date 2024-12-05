export module RenderObjectNodeLink;

import std;

export namespace RenderObject {
    struct NodeLink {
        std::string fromNode;
        std::string fromSocket;
        std::string toNode;
        std::string toSocket;
    };
}