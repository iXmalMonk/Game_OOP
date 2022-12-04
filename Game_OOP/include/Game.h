#ifndef _GAME_H
#define _GAME_H

#include "GameObject.h"

class Game
{
private:
	static Game* instance;
	
	Clock* clock;
	Event* event;
	RenderWindow* window;

	float time;

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
