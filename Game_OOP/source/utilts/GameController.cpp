#include "..\..\include\utilts\GameController.h"
#include "..\..\include\utilts\Game.h"

GameController* GameController::instance = nullptr;

GameController::GameController()
{
	currentMapNumber = 0;
	loadMap(FILENAME_MAP_1, 1);
}

void GameController::loadMap(const char* _filename, int _mapNumber)
{
	ifstream file;
	file.open(_filename);
	for (int i = 0; i < MAP_SIZE; i++)
		getline(file, map[_mapNumber - 1][i]);
	file.close();
}

void GameController::createMap()
{
	for(int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[currentMapNumber][i][j] == 'b')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::BRICKWALL,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[currentMapNumber][i][j] == 'c')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::CONCRETEWALL,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[currentMapNumber][i][j] == 'f')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::FOREST,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[currentMapNumber][i][j] == 'h')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::HEADQUARTERS,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[currentMapNumber][i][j] == 'w')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::WATER,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
}

void GameController::createTanks()
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[currentMapNumber][i][j] == '0')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::PLAYER,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[currentMapNumber][i][j] == '1')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[currentMapNumber][i][j] == '2')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[currentMapNumber][i][j] == '3')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
}

void GameController::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

GameController* GameController::getInstance()
{
	if (!instance)
		instance = new GameController;
	return instance;
}

void GameController::message(GameObject::Message* _message)
{
	if (_message->messageType == GameObject::MessageType::DESTROY)
	{
		if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::PLAYER)
		{
			for (int i = 0; i < MAP_SIZE; i++)
				for (int j = 0; j < MAP_SIZE; j++)
					if (map[currentMapNumber][i][j] == '0')
						Game::getInstance()->message(new GameObject::Message(NULL,
							GameObject::GameObjectType::PLAYER,
							Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
							GameObject::MessageType::CREATE));
		}
		else if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::ENEMY)
		{
			int random = rand() % 3;
			char position;
			if (random == 0)
				position = '1';
			else if (random == 1)
				position = '2';
			else
				position = '3';
			for (int i = 0; i < MAP_SIZE; i++)
				for (int j = 0; j < MAP_SIZE; j++)
					if (map[currentMapNumber][i][j] == position)
						Game::getInstance()->message(new GameObject::Message(NULL,
							GameObject::GameObjectType::ENEMY,
							Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
							GameObject::MessageType::CREATE));
		}
	}
}