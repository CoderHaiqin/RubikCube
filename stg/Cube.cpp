#include "Cube.h"
#include "Rotation.h"

Cube::Cube() {

}

void Cube::init(const std::vector<Square>& squares) {
	this->squares.clear();

	for (const Square& square : squares) {
		this->squares.push_back(square);
	}
}

void Cube::rotate(char axis, int direction, int n) {
	glm::mat4 mat = Rotation::getRotationMat(axis, direction, n);
	for (Square& square : squares) {
		square.rotate(mat);
	}
}

void Cube::rotate(const glm::mat4& mat) {
	for (Square& square : squares) {
		square.rotate(mat);
	}
}

void Cube::draw(Render &render) {
	for (Square& square : squares) {
		square.draw(render);
	}
}