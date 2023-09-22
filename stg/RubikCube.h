#pragma once
#include "Cube.h"
#include "Render.h"
class RubikCube
{
private:
	Cube cubes[27];
	int cubeTable[3][3][3];
public:
	void initCube();

	void rotate(char axis, int direction, int n);

	void draw(Render& render);
};

