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
	
	Clock* clock;
	Event* event;
	RenderWindow* window;

	float time;

	list<GameObject*> gameObjects;
	list<GameObject::Message*> messages;

	Game();
	~Game();
	void events();
	void updateTime();
	void updateGameObjects();
	void messagesGameObjects();
	void drawGameObjects();
public:
	static Game* getInstance();
	Game* entry();
	bool exit();

	void sendMessageInGameObject(GameObject::Message* _message, GameObject* _gameObject);
	void receiveMessage(GameObject::Message* _message);
};

#endif // !_GAME_H
