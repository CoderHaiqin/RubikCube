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

	rubikCube.initCube();
}


Game& Game::getInstance()
{
	static Game game;
	return game;
}

void Game::init()
{
	rubikCube.initCube();
}

void Game::process()
{
	camera.process(keys);


}

void Game::draw()
{
	rubikCube.draw(render);

	camera.draw(render);

	render.draw();
}

void Game::release()
{

}

void Game::_sendEvent(const int event)
{

}

