#ifndef _GAMECONTROLLER_H
#define _GAMECONTROLLER_H

#include "GameObject.h"

class Game;

class GameController
{
private:
	int maxPlayerLife;
	int maxEnemyLife;
	bool playerIsAlive;
	int maxEnemiesOnMap;
	int howManyEnemiesIsAlive;
	bool mapCreated;

	int xLeft;
	int xMiddle;
	int xRight;
	int yUp;
	int yDown;

	Game* game;
public:
	GameController();
	void update();

	void sendMessageInGame(GameObject::Message* _message);
	void receiveMessage(GameObject::Message* _message);
};

#endif // !_GAMECONTROLLER_H