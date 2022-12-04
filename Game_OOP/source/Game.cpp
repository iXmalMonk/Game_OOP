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
	if (!window->isOpen())
		window->create(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);

	while (window->isOpen())
	{
		while (window->pollEvent(*event))
			if ((*event).type == Event::Closed)
				window->close();

		time = clock->getElapsedTime().asMicroseconds() / FPS;
		clock->restart();

		window->clear();
		window->display();
	}

	return this;
}

bool Game::exit()
{
	return !instance ? true : false;
}

void Game::receiveMessage(GameObject::Message* message)
{
	messages.push_back(message);
}