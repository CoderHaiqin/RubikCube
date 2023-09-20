#pragma once
#include <glad/glad.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
class Texture
{
public:
	unsigned int ID;

	Texture();
	Texture(const char* path);

	int size_x;
	int size_y;

	struct TexPos {
		int index;

		float x1, y1;
		float x2, y2;
		int sizeX, sizeY;
		TexPos(Texture& tex, int index, int x1, int y1, int sizeX, int sizeY)
			:index(index), x1((float)(x1) / tex.size_x), y1((float)(y1) / tex.size_y), x2((float)(x1 + sizeX) / tex.size_x), y2((float)(y1 + sizeY) / tex.size_y), sizeX(sizeX), sizeY(sizeY) {}
	};

	std::vector<TexPos> texList;

	void initList(const char* path);

	void bind();
};

