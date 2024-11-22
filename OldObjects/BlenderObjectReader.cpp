#pragma once

#include "ReadBlenderFile.h"

#include "BlenderObjectReader.h"
#include <windows.h>
#include <memory>
#include "VectorOutput.h"

BlenderObjectReader* BlenderObjectReader::instance = nullptr;

// Utility function to convert std::string to std::wstring
std::wstring BlenderObjectReader::string_to_wstring(const std::string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

BlenderObjectReader::BlenderObjectReader() {
    // Set PYTHONHOME to use the bundled Python interpreter
    std::string pythonHome = "./PythonForObjects";  // Ensure this is the correct path to your bundled Blender environment
    std::wstring pythonHomeW = string_to_wstring(pythonHome);

    // Initialize Python configuration
    PyStatus status;
    PyConfig config;
    PyConfig_InitPythonConfig(&config);

    // Set Python home
    status = PyConfig_SetString(&config, &config.home, pythonHomeW.c_str());
    if (PyStatus_Exception(status)) {
        PyConfig_Clear(&config);
        std::cerr << "Failed to set Python home" << std::endl;
        std::terminate();
    }

    // Initialize Python interpreter with the configuration
    status = Py_InitializeFromConfig(&config);
    if (PyStatus_Exception(status)) {
        PyConfig_Clear(&config);
        std::cerr << "Failed to initialize Python" << std::endl;
        std::terminate();
    }

    PyConfig_Clear(&config);

    // Add necessary paths for the bundled environment
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("import os");
    PyRun_SimpleString("os.environ['PYTHONPATH'] = r'.\\PythonForObjects\\scripts\\modules'");
    PyRun_SimpleString("sys.path.append(r'.\\PythonForObjects\\DLLs')");
    PyRun_SimpleString("sys.path.append(r'.\\PythonForObjects\\scripts')");
    PyRun_SimpleString("sys.path.append(r'.\\PythonForObjects\\lib')");
    PyRun_SimpleString("sys.path.append(r'.\\PythonForObjects\\scripts\\modules')");
    PyRun_SimpleString("sys.path.append(r'D:\\Visual Studio\\Distortion\\x64\\Debug')");
}

BlenderObjectReader::~BlenderObjectReader() {
    Py_Finalize();

    if (instance != nullptr) {
        delete instance;
    }
}

BlenderObjectReader* BlenderObjectReader::getInstance() {
    if (instance == nullptr) {
        instance = new BlenderObjectReader();
    }
    return instance;
}

BlenderObjectData BlenderObjectReader::readBlenderFile(const std::string& fileName) {
    BlenderObjectData blenderObjectData;

    // Run the embedded Python script
    PyRun_SimpleString(embedded_python_read_blender_data_script);

    // Import the embedded Python function
    PyObject* pModule = PyImport_AddModule("__main__"); // Borrowed reference
    PyObject* pFunc = PyObject_GetAttrString(pModule, "read_blender_data");

    if (PyCallable_Check(pFunc)) {
        // Prepare the arguments
        PyObject* pArgs = PyTuple_Pack(1, PyUnicode_DecodeFSDefault(("./Models/" + fileName + ".blend").c_str()));

        // Call the Python function
        PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);

        if (pValue != nullptr) {
            // Parse the result
            if (PyDict_Check(pValue)) {
                PyObject* pName = PyDict_GetItemString(pValue, "name");
                PyObject* pPosition = PyDict_GetItemString(pValue, "position");
                PyObject* pRotation = PyDict_GetItemString(pValue, "rotation");
                PyObject* pScale = PyDict_GetItemString(pValue, "scale");
                PyObject* pVertices = PyDict_GetItemString(pValue, "vertices");
                PyObject* pColors = PyDict_GetItemString(pValue, "colors");
                PyObject* pIndices = PyDict_GetItemString(pValue, "indices");
                PyObject* pMaterials = PyDict_GetItemString(pValue, "materials");

                if (PyUnicode_Check(pName)) {
                    blenderObjectData.name = PyUnicode_AsUTF8(pName);
                }

                if (PyList_Check(pPosition)) {
                    glm::vec3 position;
                    position.x = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pPosition, 0)));
                    position.y = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pPosition, 1)));
                    position.z = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pPosition, 2)));
                    blenderObjectData.position = position;
                }

                if (PyList_Check(pRotation)) {
                    glm::vec3 rotation;
                    rotation.x = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pRotation, 0)));
                    rotation.y = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pRotation, 1)));
                    rotation.z = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pRotation, 2)));
                    blenderObjectData.rotation = rotation;
                }

                if (PyList_Check(pScale)) {
                    glm::vec3 scale;
                    scale.x = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pScale, 0)));
                    scale.y = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pScale, 1)));
                    scale.z = static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pScale, 2)));
                    blenderObjectData.scale = scale;
                }

                if (PyList_Check(pVertices)) {
                    std::vector<float> vertices;
                    for (Py_ssize_t i = 0; i < PyList_Size(pVertices); ++i) {
                        vertices.push_back(static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pVertices, i))));
                    }
                    blenderObjectData.vertices = vertices;
                }

                if (PyList_Check(pColors)) {
                    std::vector<float> colors;
                    for (Py_ssize_t i = 0; i < PyList_Size(pColors); ++i) {
                        colors.push_back(static_cast<float>(PyFloat_AsDouble(PyList_GetItem(pColors, i))));
                    }
                    blenderObjectData.colors = colors;
                }

                if (PyList_Check(pIndices)) {
                    std::vector<unsigned int> indices;
                    for (Py_ssize_t i = 0; i < PyList_Size(pIndices); ++i) {
                        indices.push_back(static_cast<unsigned int>(PyLong_AsLong(PyList_GetItem(pIndices, i))));
                    }
                    blenderObjectData.indices = indices;
                }

                if (PyList_Check(pMaterials)) {
                    std::vector<std::string> materials;
                    for (Py_ssize_t i = 0; i < PyList_Size(pMaterials); ++i) {
                        materials.push_back(PyUnicode_AsUTF8(PyList_GetItem(pMaterials, i)));
                    }
                    blenderObjectData.materials = materials;
                }
            }
            Py_DECREF(pValue);
        }
        else {
            PyErr_Print();
            std::cerr << "Call failed" << std::endl;
        }
    }
    else {
        if (PyErr_Occurred()) PyErr_Print();
        std::cerr << "Cannot find function 'read_blender_data'" << std::endl;
    }
    Py_XDECREF(pFunc);

    return blenderObjectData;
}