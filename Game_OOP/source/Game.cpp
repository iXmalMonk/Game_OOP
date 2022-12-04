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

	for (auto object : gameObjects)
		delete object;
	gameObjects.clear();
}

Game* Game::create()
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

Game* Game::entry()
{
	gameObjects.push_back(new Player);

	if (!window->isOpen())
		window->create(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);

	while (window->isOpen())
	{
		while (window->pollEvent(*event))
			if ((*event).type == Event::Closed)
				window->close();

		time = clock->getElapsedTime().asMicroseconds() / FPS;
		clock->restart();

		for (auto message : messages)
		{
			switch (message->messageType)
			{
			case GameObject::MessageType::SHOOT:
				gameObjects.push_back(new Projectile(message->gameObject->getPosition(), message->gameObject->getDirection()));
				delete message;
				cout << "SHOOT" << endl;
				break;
			case GameObject::MessageType::DESTROY:
				auto object = find(gameObjects.begin(), gameObjects.end(), message->gameObject);
				delete* object;
				gameObjects.erase(object);
				delete message;
				cout << "DESTROY" << endl;
				break;
			}
			
		}
		messages.clear();

		for (auto object : gameObjects)
			object->update(time);

		window->clear();

		for (auto object : gameObjects)
			window->draw(object->getSprite());

		window->display();
	}

	return this;
}

bool Game::exit()
{
	return !instance ? true : false;
}

void Game::receiveMessage(GameObject::Message* _message)
{
	messages.push_back(_message);
}