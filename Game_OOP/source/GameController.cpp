#include "..\include\GameController.h"
#include "..\include\Game.h"

GameController* GameController::instance = nullptr;

// 0 - PLAYER
// 1 - ENEMY
// 2 - ENEMY
// 3 - ENEMY
// b - BRICKWALL
// c - CONCRETEWALL
// f - FOREST
// h - HEADQUARTERS
// w - WATER

GameController::GameController()
{
	map[0] =  "1      2      3";
	map[1] =  " bbcbbbbbbbcbb ";
	map[2] =  "       b       ";
	map[3] =  "fff    b    fff";
	map[4] =  "fwf    b    fwf";
	map[5] =  "fff    b    fff";
	map[6] =  "               ";
	map[7] =  "bbbbbbbbbbbbbbb";
	map[8] =  "      bbb      ";
	map[9] =  "   bbbbbbbbb   ";
	map[10] = "bb    bbb    bb";
	map[11] = " c     0     c ";
	map[12] = " c    bbb    c ";
	map[13] = " c    bhb    c ";
	map[14] = "fffff bbb fffff";
}

void GameController::createMap()
{
	for(int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[i][j] == 'b')
				for(int k = 0; k < 2; k++)
					for(int l = 0; l < 2; l++)
						Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::BRICKWALL, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j + MAP_BLOCK / 2 * l), float(MAP_UP_Y + MAP_BLOCK * i + MAP_BLOCK / 2 * k)), GameObject::MessageType::CREATE));
			else if (map[i][j] == 'c')
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::CONCRETEWALL, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j + MAP_BLOCK / 2 * l), float(MAP_UP_Y + MAP_BLOCK * i + MAP_BLOCK / 2 * k)), GameObject::MessageType::CREATE));
			else if (map[i][j] == 'f')
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::FOREST, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j + MAP_BLOCK / 2 * l), float(MAP_UP_Y + MAP_BLOCK * i + MAP_BLOCK / 2 * k)), GameObject::MessageType::CREATE));
			else if (map[i][j] == 'h')
				Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::HEADQUARTERS, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)), GameObject::MessageType::CREATE));
			else if (map[i][j] == 'w')
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::WATER, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j + MAP_BLOCK / 2 * l), float(MAP_UP_Y + MAP_BLOCK * i + MAP_BLOCK / 2 * k)), GameObject::MessageType::CREATE));
}

void GameController::createTanks()
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[i][j] == '0')
				Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::PLAYER, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)), GameObject::MessageType::CREATE));
			else if (map[i][j] == '1')
				Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::ENEMY, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)), GameObject::MessageType::CREATE));
			else if (map[i][j] == '2')
				Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::ENEMY, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)), GameObject::MessageType::CREATE));
			else if (map[i][j] == '3')
				Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::ENEMY, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)), GameObject::MessageType::CREATE));
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
					if (map[i][j] == '0')
						Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::PLAYER, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)), GameObject::MessageType::CREATE));
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
					if (map[i][j] == position)
						Game::getInstance()->message(new GameObject::Message(NULL, GameObject::GameObjectType::ENEMY, Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)), GameObject::MessageType::CREATE));
		}
	}
}
