#ifndef _GAMECONTROLLER_H
#define _GAMECONTROLLER_H

#include "GameObject.h"

class GameController
{
private:
	static GameController* instance;

	int currentMapNumber;
	string map[MAPS_AMOUNT][MAP_SIZE];

	GameController();
	void loadMap(const char* _filename, int _mapNumber);
public:
	void createMap();
	void createTanks();
	void destroy();
	static GameController* getInstance();
	void message(GameObject::Message* _message);
};

#endif // !_GAMECONTROLLER_H