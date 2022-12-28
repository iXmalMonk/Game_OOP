#include "..\include\GameController.h"
#include "..\include\Game.h"

GameController* GameController::instance = nullptr;

/*
	+-----------------------+
	|	0 - PLAYER			|
	|	1 - ENEMY			|
	|	2 - ENEMY			|
	|	3 - ENEMY			|
	|	b - BRICKWALL		|
	|	c - CONCRETEWALL	|
	|	f - FOREST			|
	|	h - HEADQUARTERS	|
	|	w - WATER			|
	+-----------------------+

	+-----------------------+
	| How to place 0, 1,	|
	|			   2, 3,	|
	|			   h		|
	|						|
	|	+--+	+--+		|
	|	|0 |	|1 |		|
	|	|  |	|  |		|
	|	+--+	+--+		|
	|						|
	|	+--+	+--+		|
	|	|2 |	|3 |		|
	|	|  |	|  |		|
	|	+--+	+--+		|
	|						|
	|	+--+				|
	|	|h |				|
	|	|  |				|
	|	+--+				|
	|						|
	+-----------------------+
*/

GameController::GameController()
{
	map[0] =  "1             2             3 ";
	map[1] =  "                              ";
	map[2] =  "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[3] =  "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[4] =  "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[5] =  "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[6] =  "  bbb  bbb  bbccbb  bbb  bbb  ";
	map[7] =  "  bbb  bbb  bbccbb  bbb  bbb  ";
	map[8] =  "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[9] =  "  bbb  bbb          bbb  bbb  ";
	map[10] = "  bbb  bbb          bbb  bbb  ";
	map[11] = "            bb  bb            ";
	map[12] = "            bb  bb            ";
	map[13] = "bb  bbbbbb          bbbbbb  bb";
	map[14] = "cc  bbbbbb          bbbbbb  cc";
	map[15] = "            bb  bb            ";
	map[16] = "            bbbbbb            ";
	map[17] = "  bbb  bbb  bbbbbb  bbb  bbb  ";
	map[18] = "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[19] = "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[20] = "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[21] = "  bbb  bbb  bb  bb  bbb  bbb  ";
	map[22] = "  bbb  bbb    0     bbb  bbb  ";
	map[23] = "  bbb  bbb          bbb  bbb  ";
	map[24] = "  bbb  bbb   bbbb   bbb  bbb  ";
	map[25] = "  bbb  bbb   bh b   bbb  bbb  ";
	map[26] = "  bbb  bbb   b  b   bbb  bbb  ";
	map[27] = "  bbb  bbb   bbbb   bbb  bbb  ";
	map[28] = "                              ";
	map[29] = "                              ";
}

void GameController::createMap()
{
	for(int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[i][j] == 'b')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::BRICKWALL,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[i][j] == 'c')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::CONCRETEWALL,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[i][j] == 'f')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::FOREST,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[i][j] == 'h')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::HEADQUARTERS,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[i][j] == 'w')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::WATER,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
}

void GameController::createTanks()
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[i][j] == '0')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::PLAYER,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[i][j] == '1')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[i][j] == '2')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j), float(MAP_UP_Y + MAP_BLOCK * i)),
					GameObject::MessageType::CREATE));
			else if (map[i][j] == '3')
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
					if (map[i][j] == '0')
						Game::getInstance()->message(new GameObject::Message(NULL,
							GameObject::GameObjectType::PLAYER,
							Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j),
								float(MAP_UP_Y + MAP_BLOCK * i)),
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
					if (map[i][j] == position)
						Game::getInstance()->message(new GameObject::Message(NULL,
							GameObject::GameObjectType::ENEMY,
							Vector2f(float(MAP_LEFT_X + MAP_BLOCK * j),
								float(MAP_UP_Y + MAP_BLOCK * i)),
							GameObject::MessageType::CREATE));
		}
	}
}
