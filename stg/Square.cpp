#include "Square.h"
#include "Rotation.h"

Square::Square() {

}

Square::Square(const Square& square) {
	position = square.position;
	wayLine = square.wayLine;
	direction = square.direction;
	tex = square.tex;
}

Square::Square(glm::vec3 _position, glm::vec4 _tex, glm::vec3 _wayLine, glm::vec3 _direction) {
	position = _position;
	tex = _tex;
	wayLine = _wayLine;
	direction = _direction;
}

void Square::rotate(char axis, int direction, int n) {
	glm::mat4 mat = Rotation::getRotationMat(axis, direction, n);
	glm::vec4 tmp = glm::vec4(wayLine, 1.0f);
	tmp = mat * tmp;
	wayLine = glm::vec3(tmp.x, tmp.y, tmp.z);

	tmp = glm::vec4(this->direction, 1.0f);
	tmp = mat * tmp;
	this->direction = glm::vec3(tmp.x, tmp.y, tmp.z);

	tmp = glm::vec4(position, 1.0f);
	tmp = mat * tmp;
	position = glm::vec3(tmp.x, tmp.y, tmp.z);
}

void Square::rotate(const glm::mat4& mat) {
	glm::vec4 tmp = glm::vec4(wayLine, 1.0f);
	tmp = mat * tmp;
	wayLine = glm::vec3(tmp.x, tmp.y, tmp.z);

	tmp = glm::vec4(this->direction, 1.0f);
	tmp = mat * tmp;
	this->direction = glm::vec3(tmp.x, tmp.y, tmp.z);

	tmp = glm::vec4(position, 1.0f);
	tmp = mat * tmp;
	position = glm::vec3(tmp.x, tmp.y, tmp.z);
}

void Square::draw(Render& render) {
	render.draw(position, tex, wayLine, direction);
} 