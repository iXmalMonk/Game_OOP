#include "..\include\GameController.h"
#include "..\include\Game.h"

GameController::GameController()
{
	maxPlayerLife = 3;
	maxEnemyLife = 20;
	playerIsAlive = false;
	maxEnemiesOnMap = 3;
	howManyEnemiesIsAlive = 0;
	mapCreated = false;

	game = Game::getInstance();
}

void GameController::update()
{
}

void GameController::sendMessageInGame(GameObject::Message* _message)
{
	game->receiveMessage(_message);
}

void GameController::receiveMessage(GameObject::Message* _message)
{
}
