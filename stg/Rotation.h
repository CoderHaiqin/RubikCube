#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Rotation
{
public:
	static glm::mat4 getRotationMat(char axis, int direction, int n);
};

