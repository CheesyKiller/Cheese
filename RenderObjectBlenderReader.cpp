#include <Python.h>

import RenderObjectBlenderReader;
import RenderObjectBlenderPython;
import RenderObjectMaterialManager;
import StaticSystemPaths;
import DebugVectorOutput;

namespace RenderObject {
    BlenderReader* BlenderReader::getInstance() {
        static BlenderReader instance;
        return &instance;
    }

    BlenderReader::~BlenderReader() {
        Py_Finalize();
    }

    BlenderReader::BlenderReader() {
        // Set PYTHONHOME to use the bundled Python interpreter
        const std::string pythonHome = "./PythonForObjects";

        // Initialize Python configuration
        PyStatus status;
        PyConfig config;
        PyConfig_InitPythonConfig(&config);

        // Set Python home using PyConfig_SetBytesString to handle char* strings
        status = PyConfig_SetBytesString(&config, &config.home, pythonHome.c_str());
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
        PyRun_SimpleString("os.environ['PYTHONPATH'] = './PythonForObjects/scripts/modules'");
        PyRun_SimpleString("sys.path.append('./PythonForObjects/DLLs')");
        PyRun_SimpleString("sys.path.append('./PythonForObjects/scripts')");
        PyRun_SimpleString("sys.path.append('./PythonForObjects/lib')");
        PyRun_SimpleString("sys.path.append('./PythonForObjects/scripts/modules')");
    }

    Data BlenderReader::read(const std::string& fileName) {
        Data data;

        // Run the embedded Python script
        if (PyRun_SimpleString(embedded_python_read_blender_data_script) != 0) {
            PyErr_Print();
            std::cerr << "Failed to run embedded Python script" << std::endl;
            return data;
        }

        // Import the embedded Python function
        PyObject* pModule = PyImport_AddModule("__main__");
        PyObject* pFunc = PyObject_GetAttrString(pModule, "read_blender_data");

        if (pFunc && PyCallable_Check(pFunc)) {
            // Prepare the arguments
            const std::string fullFilePath = StaticSystemPaths::ExecutionFolder + "/Models/" + fileName + ".blend";
            PyObject* pArg = PyUnicode_DecodeFSDefault(fullFilePath.c_str());
            if (!pArg) {
                PyErr_Print();
                std::cerr << "Failed to decode file path" << std::endl;
                Py_DECREF(pFunc);
                return data;
            }

            PyObject* pArgs = PyTuple_Pack(1, pArg);
            Py_DECREF(pArg);

            if (!pArgs) {
                PyErr_Print();
                std::cerr << "Failed to create arguments tuple" << std::endl;
                Py_DECREF(pFunc);
                return data;
            }

            // Call the Python function
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue != nullptr) {
                // Parse the result
                if (PyDict_Check(pValue)) {
                    PyObject* pName = PyDict_GetItemString(pValue, "name"); // Borrowed reference
                    PyObject* pPosition = PyDict_GetItemString(pValue, "position");
                    PyObject* pRotation = PyDict_GetItemString(pValue, "rotation");
                    PyObject* pScale = PyDict_GetItemString(pValue, "scale");
                    PyObject* pVertices = PyDict_GetItemString(pValue, "vertices");
                    PyObject* pColors = PyDict_GetItemString(pValue, "colors");
                    PyObject* pIndices = PyDict_GetItemString(pValue, "indices");
                    PyObject* pMaterials = PyDict_GetItemString(pValue, "materials");
                    PyObject* pFaceMatIndices = PyDict_GetItemString(pValue, "face_material_indices");

                    // Extract 'name'
                    if (pName && PyUnicode_Check(pName)) {
                        data.name = PyUnicode_AsUTF8(pName);
                    }

                    // Extract 'position'
                    if (pPosition && PyList_Check(pPosition)) {
                        glm::vec3 position;
                        for (int i = 0; i < 3; ++i) {
                            PyObject* item = PyList_GetItem(pPosition, i); // Borrowed reference
                            if (item) {
                                position[i] = static_cast<float>(PyFloat_AsDouble(item));
                            }
                        }
                        data.position = position;
                    }

                    // Extract 'rotation'
                    if (pRotation && PyList_Check(pRotation)) {
                        glm::vec3 rotation;
                        for (int i = 0; i < 3; ++i) {
                            PyObject* item = PyList_GetItem(pRotation, i);
                            if (item) {
                                rotation[i] = static_cast<float>(PyFloat_AsDouble(item));
                            }
                        }
                        data.rotation = rotation;
                    }

                    // Extract 'scale'
                    if (pScale && PyList_Check(pScale)) {
                        glm::vec3 scale;
                        for (int i = 0; i < 3; ++i) {
                            PyObject* item = PyList_GetItem(pScale, i);
                            if (item) {
                                scale[i] = static_cast<float>(PyFloat_AsDouble(item));
                            }
                        }
                        data.scale = scale;
                    }

                    // Extract 'vertices'
                    if (pVertices && PyList_Check(pVertices)) {
                        std::vector<float> vertices;
                        Py_ssize_t size = PyList_Size(pVertices);
                        vertices.reserve(size);
                        for (Py_ssize_t i = 0; i < size; ++i) {
                            PyObject* item = PyList_GetItem(pVertices, i);
                            if (item) {
                                vertices.push_back(static_cast<float>(PyFloat_AsDouble(item)));
                            }
                        }
                        data.vertices = std::move(vertices);
                    }

                    // Extract 'colors'
                    if (pColors && PyList_Check(pColors)) {
                        std::vector<float> colors;
                        Py_ssize_t size = PyList_Size(pColors);
                        colors.reserve(size);
                        for (Py_ssize_t i = 0; i < size; ++i) {
                            PyObject* item = PyList_GetItem(pColors, i);
                            if (item) {
                                colors.push_back(static_cast<float>(PyFloat_AsDouble(item)));
                            }
                        }
                        data.colors = std::move(colors);
                    }

                    // Extract 'indices'
                    if (pIndices && PyList_Check(pIndices)) {
                        std::vector<unsigned int> indices;
                        Py_ssize_t size = PyList_Size(pIndices);
                        indices.reserve(size);
                        for (Py_ssize_t i = 0; i < size; ++i) {
                            PyObject* item = PyList_GetItem(pIndices, i);
                            if (item) {
                                indices.push_back(static_cast<unsigned int>(PyLong_AsUnsignedLong(item)));
                            }
                        }
                        data.indices = std::move(indices);
                    }

                    // Extract 'materials'
                    if (pMaterials && PyList_Check(pMaterials)) {
                        std::vector<std::shared_ptr<Material>> materials;
                        Py_ssize_t size = PyList_Size(pMaterials);
                        materials.reserve(size);
                        for (Py_ssize_t i = 0; i < size; ++i) {
                            PyObject* item = PyList_GetItem(pMaterials, i); // item is a dict
                            if (item && PyDict_Check(item)) {
                                PyObject* pName = PyDict_GetItemString(item, "name");
                                PyObject* pBaseColor = PyDict_GetItemString(item, "baseColor");

                                if (pName && PyUnicode_Check(pName)) {
                                    const char* materialName = PyUnicode_AsUTF8(pName);
                                    if (materialName) {
                                        // Retrieve or create the material
                                        auto materialPtr = MaterialManager::getInstance().getMaterial(materialName);
                                        if (!materialPtr) {
                                            // If material doesn't exist, create and add it
                                            Material newMaterial(materialName);

                                            // Set baseColor if available
                                            if (pBaseColor && PyList_Check(pBaseColor)) {
                                                glm::vec4 baseColor;
                                                for (int j = 0; j < 4; ++j) {
                                                    PyObject* colorItem = PyList_GetItem(pBaseColor, j);
                                                    if (colorItem) {
                                                        baseColor[j] = static_cast<float>(PyFloat_AsDouble(colorItem));
                                                    }
                                                }
                                                newMaterial.baseColor = baseColor;
                                            }

                                            materialPtr = MaterialManager::getInstance().addMaterial(newMaterial);
                                        }
                                        materials.push_back(materialPtr);
                                    }
                                }
                            }
                        }
                        data.materials = std::move(materials);
                    }

                    // Extract 'face_material_indices'
                    if (pFaceMatIndices && PyList_Check(pFaceMatIndices)) {
                        std::vector<unsigned int> faceMaterialIndices;
                        Py_ssize_t size = PyList_Size(pFaceMatIndices);
                        faceMaterialIndices.reserve(size);
                        for (Py_ssize_t i = 0; i < size; ++i) {
                            PyObject* item = PyList_GetItem(pFaceMatIndices, i);
                            if (item) {
                                faceMaterialIndices.push_back(static_cast<unsigned int>(PyLong_AsUnsignedLong(item)));
                            }
                        }
                        data.faceMaterialIndices = std::move(faceMaterialIndices);
                    }

                }
                Py_DECREF(pValue);
            }
            else {
                PyErr_Print();
                std::cerr << "Call to 'read_blender_data' failed" << std::endl;
            }
        }
        else {
            if (PyErr_Occurred()) PyErr_Print();
            std::cerr << "Cannot find function 'read_blender_data'" << std::endl;
        }
        Py_XDECREF(pFunc);

        return data;
    }
}