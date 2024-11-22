#pragma once

#include <vector>

#include "BlenderObject.h"

class ShaderProgram : public std::enable_shared_from_this<ShaderProgram> {
	static std::shared_ptr<ShaderProgram> instance;
	std::vector<std::shared_ptr<BlenderObject>> currentObjects = std::vector<std::shared_ptr<BlenderObject>>();

	ShaderProgram();
public:
	unsigned int id;

	static std::shared_ptr<ShaderProgram> getInstance() {
		if (instance == nullptr) {
			instance = std::shared_ptr<ShaderProgram>(new ShaderProgram());
		}
		return instance;
	}

	~ShaderProgram();

	void addBlenderObject(std::shared_ptr<BlenderObject> blenderObject);

	void draw();
	void removeObject(std::string objectName);
};