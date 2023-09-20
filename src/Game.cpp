#include "Game.h"
#include "ResourceManager.h"
#include "Rotation.h"

Game::Game() : shader("../shader/vShader.txt", "../shader/fShader.txt"), render(shader)
{
	Texture textureTex("../img/texture.png");
	textureTex.initList("../img/texture.txt");
	ResourceManager::insertTexture("texture", textureTex);
	shader.setInt("total_length", textureTex.size_x);
	shader.setInt("total_height", textureTex.size_y);
	srand(time(NULL));

	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	initCube();
}

void Game::initCube() {
	Square squareTable[6] = {
		Square(glm::vec3(0, 0, 0), glm::vec4(0, 0, 1, 1), glm::vec3(0, 0, -1), glm::vec3(-1, 0, 0)),
		Square(glm::vec3(0, 0, 0), glm::vec4(0, 0, 1, 1), glm::vec3(0, 0, 1), glm::vec3(1, 0, 0)),
		Square(glm::vec3(0, 0, 0), glm::vec4(0, 0, 1, 1), glm::vec3(0, -1, 0), glm::vec3(-1, 0, 0)),
		Square(glm::vec3(0, 0, 0), glm::vec4(0, 0, 1, 1), glm::vec3(0, 1, 0), glm::vec3(1, 0, 0)),
		Square(glm::vec3(0, 0, 0), glm::vec4(0, 0, 1, 1), glm::vec3(-1, 0, 0), glm::vec3(0, 1, 0)),
		Square(glm::vec3(0, 0, 0), glm::vec4(0, 0, 1, 1), glm::vec3(1, 0, 0), glm::vec3(0, -1, 0)),
	};
	Texture& texture = ResourceManager::getTexture("texture");
	

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				std::vector<Square> squares;
				if (i == 0) {
					Square square = squareTable[0];
					square.position = glm::vec3(k - 1, j - 1, i - 1 - 0.5f);
					square.tex = glm::vec4(texture.texList[0].x1,
						texture.texList[0].y1,
						(float)texture.texList[0].sizeX / texture.size_x,
						(float)texture.texList[0].sizeY / texture.size_y);
					squares.push_back(square);
				}
				else if (i == 2) {
					Square square = squareTable[1];
					square.position = glm::vec3(k - 1, j - 1, i - 1 + 0.5f);
					square.tex = glm::vec4(texture.texList[1].x1,
						texture.texList[1].y1,
						(float)texture.texList[1].sizeX / texture.size_x,
						(float)texture.texList[1].sizeY / texture.size_y);
					squares.push_back(square);
				}

				if (j == 0) {
					Square square = squareTable[2];
					square.position = glm::vec3(k - 1, j - 1 - 0.5f, i - 1);
					square.tex = glm::vec4(texture.texList[2].x1,
						texture.texList[2].y1,
						(float)texture.texList[2].sizeX / texture.size_x,
						(float)texture.texList[2].sizeY / texture.size_y);
					squares.push_back(square);
				}
				else if (j == 2) {
					Square square = squareTable[3];
					square.position = glm::vec3(k - 1, j - 1 + 0.5f, i - 1);
					square.tex = glm::vec4(texture.texList[3].x1,
						texture.texList[3].y1,
						(float)texture.texList[3].sizeX / texture.size_x,
						(float)texture.texList[3].sizeY / texture.size_y);
					squares.push_back(square);
				}

				if (k == 0) {
					Square square = squareTable[4];
					square.position = glm::vec3(k - 1 - 0.5f, j - 1, i - 1);
					square.tex = glm::vec4(texture.texList[4].x1,
						texture.texList[4].y1,
						(float)texture.texList[4].sizeX / texture.size_x,
						(float)texture.texList[4].sizeY / texture.size_y);
					squares.push_back(square);
				}
				else if (k == 2) {
					Square square = squareTable[5];
					square.position = glm::vec3(k - 1 + 0.5f, j - 1, i - 1);
					square.tex = glm::vec4(texture.texList[5].x1,
						texture.texList[5].y1,
						(float)texture.texList[5].sizeX / texture.size_x,
						(float)texture.texList[5].sizeY / texture.size_y);
					squares.push_back(square);
				}
				cubes[9 * i + 3 * j + k].init(squares);
				cubeTable[k][j][i] = 9 * i + 3 * j + k;
			}
		}
	}

	


}

void Game::rotate(char face, int direction, int n) {
	int table[9][3] = {0};
	char axis = 0;
	if (face == 'U') {
		axis = 'z';
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				table[3 * i + j][0] = i-1;
				table[3 * i + j][1] = j-1;
				table[3 * i + j][2] = 1;
			}
		}
	}
	else if (face == 'D') {
		axis = 'z';
		direction = -direction;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				table[3 * i + j][0] = i-1;
				table[3 * i + j][1] = j-1;
				table[3 * i + j][2] = -1;
			}
		}
	}
	else if (face == 'R') {
		axis = 'x';
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				table[3 * i + j][0] = 1;
				table[3 * i + j][1] = i-1;
				table[3 * i + j][2] = j-1;
			}
		}
	}
	else if (face == 'L') {
		axis = 'x';
		direction = -direction;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				table[3 * i + j][0] = -1;
				table[3 * i + j][1] = i-1;
				table[3 * i + j][2] = j-1;
			}
		}
	}
	else if (face == 'F') {
		axis = 'y';
		direction = -direction;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				table[3 * i + j][0] = i-1;
				table[3 * i + j][1] = -1;
				table[3 * i + j][2] = j - 1;
			}
		}
	}
	else if (face == 'B') {
		axis = 'y';
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				table[3 * i + j][0] = i - 1;
				table[3 * i + j][1] = 1;
				table[3 * i + j][2] = j - 1;
			}
		}
	}
	else {
		return;
	}

	int target[9][4] = { 0 };
	for (int i = 0; i < 9; i++) {
		int x = table[i][0];
		int y = table[i][1];
		int z = table[i][2];

		int cur = cubeTable[x+1][y+1][z+1];
		cubes[cur].rotate(axis, direction, n);
		glm::vec4 curPos = glm::vec4(x, y, z, 1.0f);
		glm::vec4 newPos = Rotation::getRotationMat(axis, direction, n) * curPos;
		int nx = newPos.x;
		int ny = newPos.y;
		int nz = newPos.z;
		target[i][0] = nx;
		target[i][1] = ny;
		target[i][2] = nz;
		target[i][3] = cur;
	}
	for (int i = 0; i < 9; i++) {
		int nx = target[i][0];
		int ny = target[i][1];
		int nz = target[i][2];
		cubeTable[nx + 1][ny + 1][nz + 1] = target[i][3];
	}
}

Game& Game::getInstance()
{
	static Game game;
	return game;
}

void Game::init()
{
	for (int i = 0; i < 4; i++) {
		rotate('R', 1, 1);
		rotate('U', 1, 1);
		rotate('R', -1, 1);
		rotate('U', -1, 1);
	}

}

void Game::process()
{
	camera.process(keys);


}

void Game::draw()
{
	for (int i = 0; i < 27; i++) {
		cubes[i].draw(render);
	}
	camera.draw(render);

	render.draw();
}

void Game::release()
{

}

void Game::_sendEvent(const int event)
{

}

