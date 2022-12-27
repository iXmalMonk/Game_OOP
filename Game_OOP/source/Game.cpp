#include "..\include\Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
	gameWindow = GameWindow::getInstance();
	gameResources = GameResources::getInstance();
	CONSOLE ? console::show() : console::hide();
}

Game::~Game()
{
	gameWindow->destroy();
	gameResources->destroy();
	for (auto gameObject : gameObjects)
		delete gameObject;
	gameObjects.clear();
	for (auto message : messages)
		delete message;
	messages.clear();
}

int Game::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
		return 0;
	}
	return 1;
}

void Game::msgs()
{
	for (auto message : messages)
	{
		switch (message->messageType)
		{
		case GameObject::MessageType::CREATE:
		{
			switch (message->create.gameObjectType)
			{
			case GameObject::GameObjectType::BRICKWALL:
				gameObjects.push_back(new BrickWall(message->create.position));
				break;
			case GameObject::GameObjectType::CONCRETEWALL:
				gameObjects.push_back(new ConcreteWall(message->create.position));
				break;
			case GameObject::GameObjectType::ENEMY:
				gameObjects.push_back(new Enemy(message->create.position));
				break;
			case GameObject::GameObjectType::FLAG:
				gameObjects.push_back(new Flag(message->create.position));
				break;
			case GameObject::GameObjectType::FOREST:
				gameObjects.push_back(new Forest(message->create.position));
				break;
			case GameObject::GameObjectType::HEADQUARTERS:
				gameObjects.push_back(new Headquarters(message->create.position));
				break;
			case GameObject::GameObjectType::PLAYER:
				gameObjects.push_back(new Player(message->create.position));
				break;
			case GameObject::GameObjectType::PROJECTILE:
				gameObjects.push_back(new Projectile(message->gameObject->getDirection(), message->gameObject, message->create.position));
				break;
			case GameObject::GameObjectType::WATER:
				gameObjects.push_back(new Water(message->create.position));
				break;
			}
			break;
		}
		case GameObject::MessageType::DEALDAMAGE:
		case GameObject::MessageType::EMPTY:
		{
			for (auto gameObject : gameObjects)
				gameObject->message(message);
			break;
		}
		case GameObject::MessageType::DESTROY:
		{
			auto object = find(gameObjects.begin(),
				gameObjects.end(),
				message->gameObject);
			delete* object;
			gameObjects.erase(object);
			if (MESSAGES_DEBUG_IN_GAME)
				cout << "DESTROY" << endl;
			break;
		}
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

int Game::game()
{
	if (instance)
	{
		//
		gameObjects.push_back(new Player(Vector2f(WINDOW_W / 2, WINDOW_H / 2)));
		gameObjects.push_back(new Enemy(Vector2f(WINDOW_W - TANK_W, 0)));
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				//if (j < 2)
				gameObjects.push_back(new BrickWall(Vector2f(float(WINDOW_W / 6 + j * STATICOBJECT_SMALL_W), float(WINDOW_H / 4 + i * STATICOBJECT_SMALL_H))));
		//else if (j < 4)
			//gameObjects.push_back(new Water(Vector2f(float(WINDOW_W / 6 + j * STATICOBJECT_SMALL_W), float(WINDOW_H / 4 + i * STATICOBJECT_SMALL_H))));
		//else if (j < 6)
			//gameObjects.push_back(new ConcreteWall(Vector2f(float(WINDOW_W / 6 + j * STATICOBJECT_SMALL_W), float(WINDOW_H / 4 + i * STATICOBJECT_SMALL_H))));
		//else
			//gameObjects.push_back(new Forest(Vector2f(float(WINDOW_W / 6 + j * STATICOBJECT_SMALL_W), float(WINDOW_H / 4 + i * STATICOBJECT_SMALL_H))));
		gameObjects.push_back(new Headquarters(Vector2f(float(WINDOW_W / 1.5), float(WINDOW_H / 1.5))));
		//
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
	}
	return destroy();
}

Game* Game::getInstance()
{
	if (!instance)
		instance = new Game;
	return instance;
}

Texture* Game::getTexture(GameObject::GameObjectType _gameObjectType)
{
	return gameResources->getTexture(_gameObjectType);
}

void Game::message(GameObject::Message* _message)
{
	messages.push_back(_message);
}