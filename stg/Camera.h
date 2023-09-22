#pragma once
#include "Render.h"

class Camera
{
public:
	Camera();
	Camera(glm::vec3 position, glm::vec2 angle);

	glm::vec3 position;
	glm::vec2 angle;

	void process(bool* keys, double xoffset, double yoffset);

	void draw(Render& render);
};

