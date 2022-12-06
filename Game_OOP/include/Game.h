#ifndef _GAME_H
#define _GAME_H

#include "GameObject.h"
#include "Player.h"
#include "Projectile.h"

class Game
{
private:
	static Game* instance;
	
	Clock* clock;
	Event* event;
	RenderWindow* window;

	float time;

	list<GameObject*> gameObjects;
	list<GameObject::Message*> messages;

	Game();
	~Game();
	void receiveMessage();
public:
	static Game* create();
	static Game* destroy();
	Game* entry();
	bool exit();
};

#endif // !_GAME_H
