#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

Texture::Texture()
{

}
Texture::Texture(const char* path)
{
	unsigned char* data;
	int width;
	int height;
	int nrChannels;

	data = stbi_load(path, &width, &height, &nrChannels, 0);

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::initList(const char* path)
{
	std::string line;
	std::ifstream descFile;

	descFile.open(path);
	std::stringstream stream;
	int index = 0;

	getline(descFile, line);
	stream << line;
	stream >> size_x >> size_y;
	std::cout << size_x << size_y << std::endl;
	stream.clear();
	stream.str("");

	while (getline(descFile, line)) {
		stream << line;
		
		int x, y, size_x, size_y;
		stream >> x >> y >> size_x >> size_y;
		texList.push_back(TexPos(*this, index, x, y, size_x, size_y));

		stream.clear();
		stream.str("");
		index++;
	}
}

