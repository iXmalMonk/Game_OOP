#ifndef _GAME_H
#define _GAME_H

#include "..\staticObjects\BrickWall.h"
#include "..\staticObjects\ConcreteWall.h"
#include "..\utilts\Console.h"
#include "..\dynamicObjects\Enemy.h"
#include "..\staticObjects\Flag.h"
#include "..\staticObjects\Forest.h"
#include "..\utilts\GameController.h"
#include "..\utilts\GameMenu.h"
#include "..\abstract\GameObject.h"
#include "..\utilts\GameResources.h"
#include "..\utilts\GameWindow.h"
#include "..\staticObjects\Headquarters.h"
#include "..\dynamicObjects\Player.h"
#include "..\dynamicObjects\Projectile.h"
#include "..\staticObjects\Water.h"

class Game
{
private:
	static Game* instance;

	GameController* gameController;
	GameMenu* gameMenu;
	GameResources* gameResources;
	GameWindow* gameWindow;
	list<GameObject*> gameObjects;
	list<GameObject::Message*> messages;

	Game();
	~Game();
	int destroy();
	void drawGameObjects();
	void msgs();
	void updateGameObjects();

public:
	int game();
	static Game* getInstance();
	void message(GameObject::Message* _message);
};

#endif // !_GAME_H