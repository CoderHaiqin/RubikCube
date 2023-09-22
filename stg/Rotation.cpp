#include "Rotation.h"

glm::mat4 Rotation::getRotationMat(char axis, int direction, int n) {
	int sin_array[4] = { 0, 1, 0, -1 };
	int cos_array[4] = { 1, 0, -1, 0 };

	int sin_value = direction * sin_array[n % 4];
	int cos_value = direction * cos_array[n % 4];

	if (axis == 'x') {
		return glm::mat4(glm::vec4(1, 0, 0, 0),
			glm::vec4(0, cos_value, -sin_value, 0),
			glm::vec4(0, sin_value, cos_value, 0),
			glm::vec4(0, 0, 0, 1));
	}
	if (axis == 'y') {
		return glm::mat4(glm::vec4(cos_value, 0, sin_value, 0),
			glm::vec4(0, 1, 0, 0),
			glm::vec4(-sin_value, 0, cos_value, 0),
			glm::vec4(0, 0, 0, 1));
	}
	if (axis == 'z') {
		return glm::mat4(glm::vec4(cos_value, -sin_value, 0, 0),
			glm::vec4(sin_value, cos_value, 0, 0),
			glm::vec4(0, 0, 1, 0),
			glm::vec4(0, 0, 0, 1));
	}
	return glm::mat4(1.0f);
}