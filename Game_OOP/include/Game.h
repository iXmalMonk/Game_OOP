#ifndef _GAME_H
#define _GAME_H

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

class Game
{
private:
	static Game* instance;

	RenderWindow* window;

	Event* event;

	Clock* clock;
	float time;

	list<GameObject*> gameObjects;
	list<GameObject::Message*> messages;

	Game();
	~Game();
public:
	static Game* create();
	static Game* destroy();

	Game* entry();
	bool exit();

	void receiveMessage(GameObject::Message* message);
};

#endif // !_GAME_H
