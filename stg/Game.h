#pragma once
#include "Render.h"
#include "Camera.h"
#include "RubikCube.h"

#include <lua.hpp>
#include <mutex>
#include <queue>

class Game
{
private:

	Shader shader;
	Render render;

	Camera camera;

	RubikCube rubikCube;

public:
	Game();
	static Game& getInstance();

	bool keys[1024];
	double xoffset;
	double yoffset;

	void init();
	void process();

	void draw();

	void _sendEvent(const int event);

	void release();


};

