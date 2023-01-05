#include "..\..\include\utilts\GameController.h"
#include "..\..\include\utilts\Game.h"
#include "..\..\include\utilts\GameResources.h"

GameController* GameController::instance = nullptr;

GameController::GameController()
{
	continueFlag = false;
	generateLevelFlag = false;
	loseFlag = false;
	newLevelFlag = false;
	playerIsAlive = false;
	winFlag = false;
	currentNumberOfLivesAEnemy = GAMECONTROLLER_MAX_NUMBER_OF_LIVES_A_ENEMY;
	currentNumberOfLivesAPlayer = GAMECONTROLLER_MAX_NUMBER_OF_LIVES_A_PLAYER;
	currentNumberOfLivingEnemies = 0;
	currentMapNumber = 0;
	maxNumberOfLivesAEnemy = GAMECONTROLLER_MAX_NUMBER_OF_LIVES_A_ENEMY;
	maxNumberOfLivesAPlayer = GAMECONTROLLER_MAX_NUMBER_OF_LIVES_A_PLAYER;
	loadMap(FILENAME_MAP_1,
		1);
	loadMap(FILENAME_MAP_2,
		2);
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
			{
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::PLAYER,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
				playerIsAlive = true;
			}
			else if (map[currentMapNumber][i][j] == '1')
			{
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
				currentNumberOfLivingEnemies++;
			}
			else if (map[currentMapNumber][i][j] == '2')
			{
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
				currentNumberOfLivingEnemies++;
			}
			else if (map[currentMapNumber][i][j] == '3')
			{
				Game::getInstance()->message(new GameObject::Message(NULL,
					GameObject::GameObjectType::ENEMY,
					GameObject::MessageType::CREATE,
					Vector2f(float(MAP_LEFT + MAP_BLOCK * j),
						float(MAP_UP + MAP_BLOCK * i))));
				currentNumberOfLivingEnemies++;
			}
}

void GameController::loadMap(const char* _filename, int _mapNumber)
{
	ifstream file;
	file.open(_filename);
	for (int i = 0; i < MAP_SIZE; i++)
		getline(file, map[_mapNumber - 1][i]);
	file.close();
}

bool GameController::isContinue()
{
	return continueFlag;
}

bool GameController::isLose()
{
	return loseFlag;
}

bool GameController::isNewLevel()
{
	return newLevelFlag;
}

bool GameController::isWin()
{
	return winFlag;
}

GameController* GameController::getInstance()
{
	if (!instance)
		instance = new GameController;
	return instance;
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
			playerIsAlive = false;
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
				playerIsAlive = true;
				currentNumberOfLivesAPlayer--;
				GameResources::getInstance()->setCounterForText(currentNumberOfLivesAPlayer,
					GameResources::TextTypeForCounters::PLAYER);
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::ENEMY)
		{
			currentNumberOfLivingEnemies--;
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
				currentNumberOfLivingEnemies++;
				currentNumberOfLivesAEnemy--;
				GameResources::getInstance()->setCounterForText(currentNumberOfLivesAEnemy,
					GameResources::TextTypeForCounters::ENEMY);
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::HEADQUARTERS and
			!winFlag)
		{
			continueFlag = false;
			loseFlag = true;
		}
	}
	else if (_message->messageType == GameObject::MessageType::DESTROY_ALL)
	{
		if (!newLevelFlag)
		{
			loseFlag = false;
			generateLevelFlag = true;
			currentNumberOfLivesAEnemy = maxNumberOfLivesAEnemy;
			currentNumberOfLivesAPlayer = maxNumberOfLivesAPlayer;
			currentNumberOfLivingEnemies = 0;
			currentMapNumber = 0;
			playerIsAlive = false;
			winFlag = false;
			GameResources::getInstance()->setCounterForText(currentNumberOfLivesAPlayer,
				GameResources::TextTypeForCounters::PLAYER);
			GameResources::getInstance()->setCounterForText(currentNumberOfLivesAEnemy,
				GameResources::TextTypeForCounters::ENEMY);
			GameResources::getInstance()->setCounterForText(currentMapNumber + 1,
				GameResources::TextTypeForCounters::LEVEL);
		}
	}
}

void GameController::update()
{
	if (generateLevelFlag)
	{
		generateLevelFlag = false;
		continueFlag = true;
		newLevelFlag = true;
		createMap();
		createTanks();
	}
	else if (!playerIsAlive)
	{
		continueFlag = false;
		loseFlag = true;
	}
	else if (currentNumberOfLivingEnemies == 0 and
		currentMapNumber < MAP_AMOUNT - 1 and
		!loseFlag)
	{
		currentMapNumber++;
		currentNumberOfLivesAEnemy = maxNumberOfLivesAEnemy;
		newLevelFlag = true;
		GameResources::getInstance()->setCounterForText(currentNumberOfLivesAEnemy,
			GameResources::TextTypeForCounters::ENEMY);
		GameResources::getInstance()->setCounterForText(currentMapNumber + 1,
			GameResources::TextTypeForCounters::LEVEL);
		Game::getInstance()->message(new GameObject::Message(NULL,
			GameObject::MessageType::DESTROY_ALL));
		createMap();
		createTanks();
	}
	else if (currentNumberOfLivingEnemies == 0 and
		currentMapNumber == MAP_AMOUNT - 1)
	{
		continueFlag = false;
		winFlag = true;
	}
	else if (newLevelFlag)
		newLevelFlag = false;
}