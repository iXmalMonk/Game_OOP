#include "..\include\Game.h"

Game* Game::instance = nullptr;

Game::Game() : gameWindow(nullptr)
{
	gameWindow = new GameWindow;

	//CONSOLE ? Console::showConsole() : Console::hideConsole();
	CONSOLE ? console::show() : console::hide();
}

Game::~Game()
{
	delete gameWindow;

	for (auto gameObject : gameObjects)
		delete gameObject;
	gameObjects.clear();

	for (auto message : messages)
		delete message;
	messages.clear();
}

void Game::updateGameObjects()
{
	for (auto gameObject : gameObjects)
		gameObject->update(gameWindow->getTime());
}

void Game::messagesGameObjects()
{
	for (auto message : messages)
	{
		if (message->messageType == GameObject::MessageType::MOVE or
			message->messageType == GameObject::MessageType::DEALDAMAGE)
		{
			for (auto gameObject : gameObjects)
				sendMessageInGameObject(message, gameObject);
			//delete message;
			//continue;
		}

		switch (message->messageType)
		{
		case GameObject::MessageType::SHOOT:
			gameObjects.push_back(new Projectile(
				message->gameObject->getPosition(),
				message->gameObject->getDirection(),
				message->gameObject->getGameObjectType(),
				message->gameObject));
			//delete message;
			if (MESSAGES_DEBUG_IN_GAME)
				cout << "SHOOT" << endl;
			break;
		case GameObject::MessageType::DESTROY:
			auto object = find(gameObjects.begin(), gameObjects.end(), message->gameObject);
			delete* object;
			gameObjects.erase(object);
			//delete message;
			if (MESSAGES_DEBUG_IN_GAME)
				cout << "DESTROY" << endl;
			break;
		}

		delete message;
	}

	messages.clear();
}

void Game::setup()
{
	static bool flag = true;
	if (flag)
	{
		gameObjects.push_back(new Player);
		gameObjects.push_back(new Enemy(Vector2f(WINDOW_W - TANK_W, 0)));

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 5; j++)
				if (i % 3 == 0)
					gameObjects.push_back(new BrickWall(Vector2f(WINDOW_W / 4 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));
				else if (i % 3 == 1)
					gameObjects.push_back(new Water(Vector2f(WINDOW_W / 4 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));
				else
					gameObjects.push_back(new ConcreteWall(Vector2f(WINDOW_W / 4 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));
		
		//for (int i = 0; i < 10; i++)
		//	for(int j = 0; j < 10; j++)
		//		gameObjects.push_back(new BrickWall(Vector2f(WINDOW_W / 4 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));

		flag = false;
	}
}

Game* Game::getInstance()
{
	if (!instance)
		instance = new Game;

	return instance;
}

Game* Game::entry()
{
	setup();

	if (!gameWindow->isOpen())
		gameWindow->create();

	while (gameWindow->isOpen())
	{
		gameWindow->events();
		gameWindow->updateTime();
		updateGameObjects();
		messagesGameObjects();
		gameWindow->clear();
		for (auto gameObject : gameObjects)
			gameWindow->draw(gameObject->getSprite());
		gameWindow->display();
	}

	return Game::getInstance();
}

int Game::exit()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}

	return 0;
}

void Game::sendMessageInGameObject(GameObject::Message* _message, GameObject* _gameObject)
{
	_gameObject->receiveMessage(_message);
}

void Game::receiveMessage(GameObject::Message* _message)
{
	messages.push_back(_message);
}