#include "Camera.h"

Camera::Camera() {
	position = glm::vec3(0.0f, 0.0f, 10.0f);
	angle = glm::vec2(glm::radians(0.0f), glm::radians(180.0f));
}

void Camera::process(bool* keys) {
	
	if (keys[GLFW_KEY_W]) {
		glm::vec3 front = 0.1f * glm::vec3(sin(angle.y) * cos(angle.x), sin(angle.y) * sin(angle.x), cos(angle.y));
		position += front;
	}
	if (keys[GLFW_KEY_S]) {
		glm::vec3 front = 0.1f * glm::vec3(sin(angle.y) * cos(angle.x), sin(angle.y) * sin(angle.x), cos(angle.y));
		position -= front;
	}
	if (keys[GLFW_KEY_A]) {
		glm::vec3 direction = 0.1f * glm::vec3(sin(angle.x), -cos(angle.x), 0.0f);
		position -= direction;
	}
	if (keys[GLFW_KEY_D]) {
		glm::vec3 direction = 0.1f * glm::vec3(sin(angle.x), -cos(angle.x), 0.0f);
		position += direction;
	}

	if (keys[GLFW_KEY_UP]) {
		angle.y -= 0.01f;
		if (angle.y < glm::radians(-180.0f)) {
			angle.y = glm::radians(180.0f);
		}
	}

	if (keys[GLFW_KEY_DOWN]) {
		angle.y += 0.01f;
		if (angle.y > glm::radians(180.0f)) {
			angle.y = glm::radians(-180.0f);
		}
	}

	if (keys[GLFW_KEY_LEFT]) {
		angle.x += 0.01f;
		if (angle.x > glm::radians(360.0f)) {
			angle.x = glm::radians(0.0f);
		}
	}

	if (keys[GLFW_KEY_RIGHT]) {
		angle.x -= 0.01f;
		if (angle.x < glm::radians(0.0f)) {
			angle.x = glm::radians(360.0f);
		}
	}
}

void Camera::draw(Render& render) {
	glm::vec3 front = glm::vec3(sin(angle.y) * cos(angle.x), sin(angle.y) * sin(angle.x), cos(angle.y));
	glm::vec3 up = glm::vec3(-cos(angle.y) * cos(angle.x), -cos(angle.y) * sin(angle.x), sin(angle.y));
	glm::mat4 trans = glm::lookAt(position, position + front, up);
	render.handleCamera(trans);
}