#include "..\..\include\utilts\GameController.h"
#include "..\..\include\utilts\Game.h"
#include "..\..\include\utilts\GameResources.h"

GameController* GameController::instance = nullptr;

GameController::GameController()
{
	maxNumberOfLivesAEnemy = MAX_NUMBER_OF_LIVES_A_ENEMY;
	maxNumberOfLivesAPlayer = MAX_NUMBER_OF_LIVES_A_PLAYER;
	currentMapNumber = 0;
	currentNumberOfLivesAEnemy = maxNumberOfLivesAEnemy;
	currentNumberOfLivesAPlayer = maxNumberOfLivesAPlayer;
	GameResources::getInstance()->setCounterForText(currentNumberOfLivesAPlayer,
		GameResources::TextTypeForCounters::PLAYER);
	GameResources::getInstance()->setCounterForText(currentNumberOfLivesAEnemy,
		GameResources::TextTypeForCounters::ENEMY);
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

GameController* GameController::getInstance()
{
	if (!instance)
		instance = new GameController;
	return instance;
}

void GameController::createMap()
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[currentMapNumber][i][j] == 'b')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::BRICKWALL,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
			else if (map[currentMapNumber][i][j] == 'c')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::CONCRETEWALL,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
			else if (map[currentMapNumber][i][j] == 'f')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::FOREST,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
			else if (map[currentMapNumber][i][j] == 'h')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::HEADQUARTERS,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
			else if (map[currentMapNumber][i][j] == 'w')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::WATER,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
}

void GameController::createTanks()
{
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[currentMapNumber][i][j] == '0')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::PLAYER,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
			else if (map[currentMapNumber][i][j] == '1')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
			else if (map[currentMapNumber][i][j] == '2')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
			else if (map[currentMapNumber][i][j] == '3')
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
}

void GameController::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void GameController::message(GameObject::Message* _message)
{
	if (_message->messageType == GameObject::MessageType::DESTROY)
	{
		if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::PLAYER)
		{
			if (currentNumberOfLivesAPlayer > 0)
			{
				for (int i = 0; i < MAP_SIZE; i++)
					for (int j = 0; j < MAP_SIZE; j++)
						if (map[currentMapNumber][i][j] == '0')
							Game::getInstance()->message(new GameObject::Message(NULL,
								GameObject::GameObjectType::PLAYER,
								GameObject::MessageType::CREATE,
								Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
									float(MAP_UP + MAP_BLOCK * i))));
				currentNumberOfLivesAPlayer--;
				GameResources::getInstance()->setCounterForText(currentNumberOfLivesAPlayer,
					GameResources::TextTypeForCounters::PLAYER);
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::ENEMY)
		{
			if (currentNumberOfLivesAEnemy > 0)
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
								GameObject::MessageType::CREATE,
								Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
									float(MAP_UP + MAP_BLOCK * i))));
				currentNumberOfLivesAEnemy--;
				GameResources::getInstance()->setCounterForText(currentNumberOfLivesAEnemy,
					GameResources::TextTypeForCounters::ENEMY);
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::HEADQUARTERS)
		{

		}
	}
}