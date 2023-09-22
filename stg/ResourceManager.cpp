#include "ResourceManager.h"


std::map<std::string, Shader> shaderSet;
std::map<std::string, Texture> textureSet;

void ResourceManager::insertShader(const std::string& name, const Shader& shader)
{
	shaderSet[name] = shader;
}

void ResourceManager::insertTexture(const std::string& name, const Texture& texture)
{
	textureSet[name] = texture;
}

Shader ResourceManager::getShader(const std::string& name)
{
	return shaderSet.find(name)->second;
}

Texture& ResourceManager::getTexture(const std::string& name)
{
	return textureSet.find(name)->second;
}