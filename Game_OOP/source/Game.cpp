#include "..\include\Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
	gameWindow = GameWindow::getInstance();
	gameObjects.push_back(new Player(Vector2f(WINDOW_W / 2, WINDOW_H / 2)));
	gameObjects.push_back(new Enemy(Vector2f(WINDOW_W - TANK_W, 0)));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (j < 2)
				gameObjects.push_back(new BrickWall(Vector2f(WINDOW_W / 6 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));
			else if (j < 4)
				gameObjects.push_back(new Water(Vector2f(WINDOW_W / 6 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));
			else if (j < 6)
				gameObjects.push_back(new ConcreteWall(Vector2f(WINDOW_W / 6 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));
			else
				gameObjects.push_back(new Forest(Vector2f(WINDOW_W / 6 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));
	CONSOLE ? console::show() : console::hide();
}

Game::~Game()
{
	gameWindow->destroy();
	for (auto gameObject : gameObjects)
		delete gameObject;
	gameObjects.clear();
	for (auto message : messages)
		delete message;
	messages.clear();
}

void Game::msgs()
{
	for (auto message : messages)
	{
		switch (message->messageType)
		{
		case GameObject::MessageType::EMPTY:
		case GameObject::MessageType::DEALDAMAGE:
			for (auto gameObject : gameObjects)
				gameObject->message(message);
			break;
		case GameObject::MessageType::SHOOT:
			gameObjects.push_back(new Projectile(
				message->gameObject->getPosition(),
				message->gameObject->getDirection(),
				message->gameObject));
			if (MESSAGES_DEBUG_IN_GAME)
				cout << "SHOOT" << endl;
			break;
		case GameObject::MessageType::DESTROY:
			auto object = find(gameObjects.begin(),
				gameObjects.end(),
				message->gameObject);
			delete* object;
			gameObjects.erase(object);
			if (MESSAGES_DEBUG_IN_GAME)
				cout << "DESTROY" << endl;
			break;
		}
		delete message;
	}
	messages.clear();
}

void Game::update()
{
	for (auto gameObject : gameObjects)
		gameObject->update(gameWindow->getTime());
}

Game* Game::entry()
{
	if (!gameWindow->isOpen())
		gameWindow->create();
	while (gameWindow->isOpen())
	{
		gameWindow->events();
		gameWindow->updateTime();
		update();
		msgs();
		gameWindow->clear();
		for (auto gameObject : gameObjects)
			if (gameObject->getGameObjectType() != GameObject::GameObjectType::FOREST)
				gameWindow->draw(gameObject->getSprite());
		for (auto gameObject : gameObjects)
			if (gameObject->getGameObjectType() == GameObject::GameObjectType::FOREST)
				gameWindow->draw(gameObject->getSprite());
		gameWindow->display();
	}
	return instance;
}

int Game::exit()
{
	return !instance ? 0 : 1;
}

Game* Game::getInstance()
{
	if (!instance)
		instance = new Game;
	return instance;
}

Game* Game::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
	return instance;
}

void Game::message(GameObject::Message* _message)
{
	messages.push_back(_message);
}