#include "..\include\Game.h"

Game::Game() : time(0)
{
	this->window = nullptr;
	this->event = nullptr;
	this->clock = nullptr;
}

void Game::install()
{
	if (this->window == nullptr)
		this->window = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);

	if (this->event == nullptr)
		this->event = new Event;

	if (this->clock == nullptr)
		this->clock = new Clock;

	this->gameObjects.push_back(new Player);
	this->gameObjects.push_back(new Enemy);
	this->gameObjects.push_back(new Projectile);
}

void Game::uninstall()
{
	delete this->window;
	delete this->event;
	delete this->clock;

	this->window = nullptr;
	this->event = nullptr;
	this->clock = nullptr;

	this->gameObjects.clear();
}

void Game::entry()
{
	this->install();

	while (this->window->isOpen())
	{
		while (this->window->pollEvent(*this->event))
			if ((*this->event).type == Event::KeyPressed and (*this->event).key.code == Keyboard::Escape)
				this->window->close();
			else if ((*this->event).type == Event::Closed)
				this->window->close();

		this->time = (*this->clock).getElapsedTime().asMicroseconds() / FPS;
		(*this->clock).restart();

		for (auto gameObject : gameObjects)
			gameObject->update(time);

		this->window->clear();

		for (auto gameObject : gameObjects)
			this->window->draw(gameObject->getSprite());

		this->window->display();
	}

	this->uninstall();
}

int Game::exit()
{
	return (this->window == nullptr and
		this->event == nullptr and
		this->clock == nullptr and
		this->gameObjects.empty()) ? 0 : 1;
}