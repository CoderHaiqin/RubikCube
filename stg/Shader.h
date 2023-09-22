#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
class Shader
{
public:
	unsigned int ID;

	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	Shader();
	
	void use();
	void setInt(const std::string& name, int value);
	void setFloat(const std::string& name, float value);
	void setBool(const std::string& name, bool value);
	void setMat4(const std::string& name, glm::mat4& mat);
	void setVec3(const std::string& name, glm::vec3& vec3);
};

