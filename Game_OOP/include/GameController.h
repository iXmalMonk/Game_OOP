#ifndef _GAMECONTROLLER_H
#define _GAMECONTROLLER_H

#include "GameObject.h"

class Game;

class GameController
{
private:
	Game* game;

	bool mapCreated;
	bool playerIsAlive;

	int howManyEnemiesIsAlive;
	int maxEnemyLife;
	int maxEnemiesOnMap;
	int maxPlayerLife;
	int xLeft;
	int xMiddle;
	int xRight;
	int yUp;
	int yDown;

public:
	GameController();
	void update();

	void sendMessageInGame(GameObject::Message* _message);
	void receiveMessage(GameObject::Message* _message);
};

#endif // !_GAMECONTROLLER_H