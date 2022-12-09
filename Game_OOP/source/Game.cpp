#include "..\include\Game.h"

Game* Game::instance = nullptr;

Game::Game() : clock(nullptr), event(nullptr), window(nullptr), time(0)
{
	clock = new Clock;
	event = new Event;
	window = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
	window->setFramerateLimit(WINDOW_FPS);
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

void Game::events()
{
	while (window->pollEvent(*event))
		if ((*event).type == Event::Closed)
			window->close();
}

void Game::updateTime()
{
	time = clock->getElapsedTime().asMicroseconds() / TIME_COEFFICIENT;
	clock->restart();
}

void Game::updateGameObjects()
{
	for (auto gameObject : gameObjects)
		gameObject->update(time);
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
				message->gameObject->getGameObjectType(),
				message->gameObject));
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
}

void Game::drawGameObjects()
{
	window->clear();

	for (auto gameObject : gameObjects)
		window->draw(gameObject->getSprite());

	window->display();
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
	gameObjects.push_back(new Enemy(Vector2f(WINDOW_W / 2, 0)));

	for(int i = 0; i < 10; i++)
		for (int j = 0; j < 4; j++)
			gameObjects.push_back(new BrickWall(Vector2f(WINDOW_W / 4 + j * STATICOBJECT_W, WINDOW_H / 4 + i * STATICOBJECT_H)));

	gameObjects.push_back(new BrickWall(Vector2f(STATICOBJECT_W, STATICOBJECT_H)));

	if (!window->isOpen())
	{
		window->create(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
		window->setFramerateLimit(WINDOW_FPS);
	}

	while (window->isOpen())
	{
		events();
		updateTime();
		updateGameObjects();
		messagesGameObjects();
		drawGameObjects();
	}

	return this;
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