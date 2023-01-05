#ifndef _GAMECONTROLLER_H
#define _GAMECONTROLLER_H

#include "..\abstract\GameObject.h"

class GameController
{
private:
	static GameController* instance;

	bool continueFlag;
	bool generateLevelFlag;
	bool loseFlag;
	bool newLevelFlag;
	bool playerIsAlive;
	bool winFlag;
	int currentNumberOfLivesAEnemy;
	int currentNumberOfLivesAPlayer;
	int currentNumberOfLivingEnemies;
	int currentMapNumber;
	int maxNumberOfLivesAEnemy;
	int maxNumberOfLivesAPlayer;
	string map[MAP_AMOUNT][MAP_SIZE];

	GameController();
	void createMap();
	void createTanks();
	void loadMap(const char* _filename,
		int _mapNumber);

public:
	bool isContinue();
	bool isLose();
	bool isNewLevel();
	bool isWin();
	static GameController* getInstance();
	void destroy();
	void message(GameObject::Message* _message);
	void update();
};

/*
	+------------------------------+
	|	0 - PLAYER
	|	1 - ENEMY
	|	2 - ENEMY
	|	3 - ENEMY
	|	b - BRICKWALL
	|	c - CONCRETEWALL
	|	f - FOREST
	|	h - HEADQUARTERS
	|	w - WATER
	+------------------------------+

	+------------------------------+
	| How to place 0, 1, 2, 3, h:
	|
	|	+--+	+--+
	|	|0 |	|1 |
	|	|  |	|  |
	|	+--+	+--+
	|
	|	+--+	+--+
	|	|2 |	|3 |
	|	|  |	|  |
	|	+--+	+--+
	|
	|	+--+
	|	|h |
	|	|  |
	|	+--+
	|
	+------------------------------+
*/

#endif // !_GAMECONTROLLER_H