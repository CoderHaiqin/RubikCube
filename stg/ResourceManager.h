#pragma once
#include <map>
#include <string>
#include "Shader.h"
#include "Texture.h"
class ResourceManager
{

public:
	static void insertShader(const std::string& name, const Shader& shader);
	static void insertTexture(const std::string& name, const Texture& texture);

	static Shader getShader(const std::string& name);
	static Texture& getTexture(const std::string& name);
};

