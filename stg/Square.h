#pragma once
#include "Render.h"

class Square
{
private:

public:

	Square();
	Square(const Square& square);
	Square(glm::vec3 position, glm::vec4 tex, glm::vec3 wayLine, glm::vec3 direction);

	glm::vec3 position;
	glm::vec4 tex;
	glm::vec3 wayLine;
	glm::vec3 direction;

	void rotate(char axis, int direction, int n);
	void rotate(const glm::mat4& mat);

	void draw(Render &render);
};

