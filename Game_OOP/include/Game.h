#ifndef _GAME_H
#define _GAME_H

#include "..\include\GameObject.h"
#include "..\include\Player.h"
#include "..\include\Enemy.h"
#include "..\include\Projectile.h"

class Game
{
private:
	RenderWindow* window;

	Event* event;

	Clock* clock;
	float time;

	list<GameObject*> gameObjects;

	// ------------------------------
	list<GameObject::Message*> messages;
	// ------------------------------

	bool installed;
	bool uninstalled;

	bool install();
	bool uninstall();
public:
	Game();
	Game* entry();
	bool exit();
};

#endif // !_GAME_H
