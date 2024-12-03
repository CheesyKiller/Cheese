module;

#include <Windows.h>

export module StaticSystemPaths;

import std;

export namespace StaticSystemPaths {
    inline const std::string ExecutionPath = []() -> std::string {
        char buffer[MAX_PATH];
        DWORD length = GetModuleFileNameA(NULL, buffer, MAX_PATH);
        if (length > 0 && length < MAX_PATH) {
            return std::filesystem::weakly_canonical(std::filesystem::path(buffer)).string();
        }
        throw std::runtime_error("Failed to retrieve executable path");
        }();

    inline const std::string ExecutionFolder = []() -> std::string {
        char buffer[MAX_PATH];
        DWORD length = GetModuleFileNameA(NULL, buffer, MAX_PATH);
        if (length > 0 && length < MAX_PATH) {
            // Get the parent path of the executable's full path
            return std::filesystem::path(buffer).parent_path().string();
        }
        throw std::runtime_error("Failed to retrieve execution folder");
        }();
}