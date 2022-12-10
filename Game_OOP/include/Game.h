#ifndef _GAME_H
#define _GAME_H

#include "Console.h"
#include "GameWindow.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "BrickWall.h"

class Game
{
private:
	static Game* instance;
	
	GameWindow* gameWindow;

	list<GameObject*> gameObjects;
	list<GameObject::Message*> messages;

	Game();
	~Game();
	void updateGameObjects();
	void messagesGameObjects();
	void setup();
public:
	static Game* getInstance();
	Game* entry();
	int exit();

	void sendMessageInGameObject(GameObject::Message* _message, GameObject* _gameObject);
	void receiveMessage(GameObject::Message* _message);
};

#endif // !_GAME_H