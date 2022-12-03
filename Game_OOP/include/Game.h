#ifndef _GAME_H
#define _GAME_H

#include "../include/GameObject.h"
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Projectile.h"

class Game
{
private:
	RenderWindow* window;

	Event* event;

	Clock* clock;
	float time;

	list<GameObject*> gameObjects;
	
	void install();
	void uninstall();
public:
	Game();
	void entry();
	int exit();
};

#endif // !_GAME_H
