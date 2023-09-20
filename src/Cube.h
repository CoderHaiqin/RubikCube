#pragma once
#include "Square.h"
#include <vector>

class Cube
{
private:
	std::vector<Square> squares;

public:
	Cube();
	void init(const std::vector<Square>& suqares);
	void rotate(char axis, int direction, int n);
	void rotate(const glm::mat4& mat);
	void draw(Render &render);
};

