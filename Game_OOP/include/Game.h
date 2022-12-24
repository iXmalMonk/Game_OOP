#ifndef _GAME_H
#define _GAME_H

#include "BrickWall.h"
#include "ConcreteWall.h"
#include "Console.h"
#include "Enemy.h"
#include "Flag.h"
#include "Forest.h"
#include "GameObject.h"
#include "GameWindow.h"
#include "Headquarters.h"
#include "Player.h"
#include "Projectile.h"
#include "Water.h"

class Game
{
private:
	static Game* instance;

	GameWindow* gameWindow;
	list<GameObject*> gameObjects;
	list<GameObject::Message*> messages;

	Game();
	~Game();
	void msgs();
	void update();

public:
	Game* entry();
	int exit();
	static Game* getInstance();
	static Game* destroy();
	void message(GameObject::Message* _message);
};

#endif // !_GAME_H