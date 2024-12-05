export module RenderObjectBlenderReader;

import std.core;
import RenderObjectData;

export namespace RenderObject {
    struct BlenderReader {
        static BlenderReader* getInstance();
        ~BlenderReader();

        Data read(const std::string& fileName);

        BlenderReader(const BlenderReader&) = delete;
        BlenderReader& operator=(const BlenderReader&) = delete;

    private:
        BlenderReader();
    };
}