#pragma once
#include "Shader.h"
#include "Texture.h"
#include "constant.h"
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Render
{
	unsigned int VAO;
	Shader shader;
	void init();

	glm::vec3 position[MAXNUM_OF_OBJS];
	glm::vec4 tex[MAXNUM_OF_OBJS];
	glm::vec3 wayLine[MAXNUM_OF_OBJS];
	glm::vec3 direction[MAXNUM_OF_OBJS];

	int count;

public:
	Render(Shader& shader);

	void draw(glm::vec3 &position, glm::vec4 &tex, glm::vec3 &wayLine, glm::vec3 &direction);

	void handleCamera(glm::mat4& trans);

	void draw();
};
