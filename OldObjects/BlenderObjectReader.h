#pragma once

#include "BlenderObject.h"

class BlenderObjectReader {
private:
    static BlenderObjectReader* instance;

    std::wstring string_to_wstring(const std::string& str);

    BlenderObjectReader();
    ~BlenderObjectReader();
public:
    static BlenderObjectReader* getInstance();
    BlenderObjectData readBlenderFile(const std::string& fileName);
};