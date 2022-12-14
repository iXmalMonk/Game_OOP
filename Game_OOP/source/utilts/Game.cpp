#include "..\..\include\utilts\Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
	gameController = GameController::getInstance();
	gameMenu = GameMenu::getInstance();
	gameResources = GameResources::getInstance();
	gameWindow = GameWindow::getInstance();
	CONSOLE ? console::show() : console::hide();
}

Game::~Game()
{
	gameController->destroy();
	gameMenu->destroy();
	gameResources->destroy();
	gameWindow->destroy();
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

void Game::drawGameObjects()
{
	for (auto gameObject : gameObjects)
		if (gameObject->getGameObjectType() != GameObject::GameObjectType::FOREST)
			gameWindow->draw(gameObject->getSprite());
	for (auto gameObject : gameObjects)
		if (gameObject->getGameObjectType() == GameObject::GameObjectType::FOREST)
			gameWindow->draw(gameObject->getSprite());
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
				gameObjects.push_back(new Projectile(message->gameObject->getDirection(),
					message->gameObject,
					message->gameObject->getGameObjectType(),
					message->create.position));
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
			gameController->message(message);
			auto object = find(gameObjects.begin(),
				gameObjects.end(),
				message->gameObject);
			delete* object;
			gameObjects.erase(object);
			break;
		}
		case GameObject::MessageType::DESTROY_ALL:
		{
			gameController->message(message);
			for (auto gameObject : gameObjects)
				delete gameObject;
			gameObjects.clear();
			break;
		}
		case GameObject::MessageType::DESTROY_THE_WHOLE_TYPE:
		{
			list<GameObject*> destroyedGameObjects;
			for (auto gameObject : gameObjects)
				if (gameObject->getGameObjectType() == message->destroyTheWholeType.gameObjectType)
				{
					delete gameObject;
					destroyedGameObjects.push_back(gameObject);
				}
			for (auto destroyedGameObject : destroyedGameObjects)
				gameObjects.remove(destroyedGameObject);
			destroyedGameObjects.clear();
			break;
		}
		}
		delete message;
	}
	messages.clear();
}

void Game::updateGameObjects()
{
	for (auto gameObject : gameObjects)
		gameObject->update(gameWindow->getTime());
}

int Game::game()
{
	if (instance)
	{
		while (gameWindow->isOpen())
		{
			gameWindow->clear();
			gameWindow->events();
			gameWindow->updateTime();
			if (gameMenu->isMenu())
			{
				gameMenu->updateMenu();
				gameMenu->drawMenu();
			}
			else if (gameMenu->isGame())
			{
				gameMenu->updateGame(gameWindow->getTime());
				if (gameMenu->isLevel())
					gameMenu->drawGameLevel();
				else
				{
					updateGameObjects();
					msgs();
					gameController->update();
					if (!gameController->isNewLevel())
					{
						gameMenu->drawGameFirstLayer();
						drawGameObjects();
						gameMenu->drawGameLastLayer();
					}
				}
			}
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

void Game::message(GameObject::Message* _message)
{
	messages.push_back(_message);
}