#pragma once
#include "Render.h"
#include "Square.h"
#include "Cube.h"
#include "Camera.h"

#include <lua.hpp>
#include <mutex>
#include <queue>

class Game
{
private:

	Shader shader;
	Render render;


	Camera camera;

	Cube cubes[27];
	int cubeTable[3][3][3];

	void initCube();

	void rotate(char axis, int direction, int n);

public:
	Game();
	static Game& getInstance();

	bool keys[1024];

	void init();
	void process();


	void draw();

	void _sendEvent(const int event);

	void release();


};

