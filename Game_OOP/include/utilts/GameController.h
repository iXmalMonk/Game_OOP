#ifndef _GAMECONTROLLER_H
#define _GAMECONTROLLER_H

#include "..\abstract\GameObject.h"

class GameController
{
private:
	static GameController* instance;

	int currentNumberOfLivesAEnemy;
	int currentNumberOfLivesAPlayer;
	int currentMapNumber;
	int maxNumberOfLivesAEnemy;
	int maxNumberOfLivesAPlayer;
	string map[MAPS_AMOUNT][MAP_SIZE];

	GameController();
	void loadMap(const char* _filename,
		int _mapNumber);

public:
	static GameController* getInstance();
	void createMap();
	void createTanks();
	void destroy();
	void message(GameObject::Message* _message);
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