#ifndef _GAMECONTROLLER_H
#define _GAMECONTROLLER_H

#include "GameObject.h"

class GameController
{
private:
	static GameController* instance;

	string map[MAP_SIZE];

	GameController();

public:
	void createMap();
	void createTanks();
	void destroy();
	static GameController* getInstance();
	void message(GameObject::Message* _message);
};

#endif // !_GAMECONTROLLER_H
