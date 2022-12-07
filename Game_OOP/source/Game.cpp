#include "..\include\Game.h"

Game* Game::instance = nullptr;

Game::Game() : clock(nullptr), event(nullptr), window(nullptr), time(0)
{
	clock = new Clock;
	event = new Event;
	window = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
}

Game::~Game()
{
	delete clock;
	delete event;
	delete window;

	for (auto gameObject : gameObjects)
		delete gameObject;
	gameObjects.clear();

	for (auto message : messages)
		delete message;
	messages.clear();
}

Game* Game::getInstance()
{
	if (!instance)
		instance = new Game;

	return instance;
}

Game* Game::entry()
{
	gameObjects.push_back(new Player);
	gameObjects.push_back(new Enemy);

	if (!window->isOpen())
		window->create(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);

	while (window->isOpen())
	{
		while (window->pollEvent(*event))
			if ((*event).type == Event::Closed)
				window->close();

		time = clock->getElapsedTime().asMicroseconds() / FPS;
		clock->restart();

		for (auto gameObject : gameObjects)
			gameObject->update(time);

		for (auto message : messages)
		{
			if (message->messageType == GameObject::MessageType::MOVE)
			{
				for (auto gameObject : gameObjects)
					sendMessageInGameObject(message, gameObject);
				delete message;
				continue;
			}

			switch (message->messageType)
			{
			case GameObject::MessageType::SHOOT:
				gameObjects.push_back(new Projectile(
					message->gameObject->getPosition(),
					message->gameObject->getDirection(),
					message->gameObject->getW(),
					message->gameObject->getH(),
					message->gameObject->getGameObjectType()));
				delete message;
				if (MESSAGES_DEBUG_IN_GAME)
					cout << "SHOOT" << endl;
				break;
			case GameObject::MessageType::DESTROY:
				auto object = find(gameObjects.begin(), gameObjects.end(), message->gameObject);
				delete* object;
				gameObjects.erase(object);
				delete message;
				if (MESSAGES_DEBUG_IN_GAME)
					cout << "DESTROY" << endl;
				break;
			}
		}
		messages.clear();

		window->clear();

		for (auto gameObject : gameObjects)
			window->draw(gameObject->getSprite());

		window->display();
	}

	return this;
}

bool Game::exit()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}

	return !instance ? true : false;
}

void Game::sendMessageInGameObject(GameObject::Message* _message, GameObject* _gameObject)
{
	_gameObject->receiveMessage(_message);
}

void Game::receiveMessage(GameObject::Message* _message)
{
	messages.push_back(_message);
}