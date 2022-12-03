#include "..\include\Game.h"

Game::Game() : time(0), installed(false), uninstalled(true)
{
	this->window = nullptr;
	this->event = nullptr;
	this->clock = nullptr;
}

bool Game::install()
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

	this->uninstalled = false;

	return true;
}

bool Game::uninstall()
{
	delete this->window;
	delete this->event;
	delete this->clock;

	this->window = nullptr;
	this->event = nullptr;
	this->clock = nullptr;

	for (auto gameObject : this->gameObjects)
		delete gameObject;

	this->gameObjects.clear();

	this->installed = false;

	return true;
}

Game* Game::entry()
{
	if (!this->installed)
		this->installed = this->install();
	else
		this->window->create(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);

	while (this->window->isOpen())
	{
		while (this->window->pollEvent(*this->event))
			if ((*this->event).type == Event::KeyPressed and (*this->event).key.code == Keyboard::Escape)
				this->window->close();
			else if ((*this->event).type == Event::Closed)
				this->window->close();

		this->time = (*this->clock).getElapsedTime().asMicroseconds() / FPS;
		(*this->clock).restart();

		for (auto gameObject : this->gameObjects)
			gameObject->update(time);

		// ------------------------------
		for (auto message : this->messages)
		{
			switch (message->messageType)
			{
			case GameObject::MessageType::Create:
				this->gameObjects.push_back(message->create.object);
				break;

			case GameObject::MessageType::Death:
				auto object = find(this->gameObjects.begin(), this->gameObjects.end(), message->death.object);
				delete* object;
				this->gameObjects.erase(object);
				break;
			}
		}
		// ------------------------------

		this->window->clear();

		for (auto gameObject : this->gameObjects)
			this->window->draw(gameObject->getSprite());

		this->window->display();
	}

	return this;
}

bool Game::exit()
{
	return !this->uninstalled ? this->uninstalled = this->uninstall() : !this->uninstalled;
}