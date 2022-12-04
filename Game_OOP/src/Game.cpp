#include "..\include\Game.h"

Game* Game::instance = nullptr;

Game::Game() : window(nullptr), event(nullptr), clock(nullptr), time(0), gameObjects(), /**/messages()/**/
{
	this->window = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
	this->event = new Event;
	this->clock = new Clock;
}

Game::~Game()
{
	delete this->window;
	delete this->event;
	delete this->clock;

	for (auto gameObject : this->gameObjects)
		delete gameObject;

	this->gameObjects.clear();

	for (auto message : this->messages)
		delete message;

	this->messages.clear();
}

Game* Game::create()
{
	if (!instance) instance = new Game();
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
	if (instance)
	{
		this->gameObjects.push_back(new Player);
		this->gameObjects.push_back(new Enemy);

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
			
			//for (auto message : this->messages)
			//{
			//	switch (message->messageType)
			//	{
			//	case GameObject::MessageType::Create:
			//		this->gameObjects.push_back(message->create.object);
			//		break;
			//
			//	case GameObject::MessageType::Death:
			//		auto object = find(this->gameObjects.begin(), this->gameObjects.end(), message->death.object);
			//		delete* object;
			//		this->gameObjects.erase(object);
			//		break;
			//	}
			//}
			//
			//for (auto message : this->messages)
			//	delete message;
			//
			//this->messages.clear();

			this->window->clear();

			for (auto gameObject : this->gameObjects)
				this->window->draw(gameObject->getSprite());

			this->window->display();
		}
	}
	
	return this;
}

bool Game::exit()
{
	return !instance ? true : false;
}

void Game::receiveMessage(GameObject::Message* message)
{
	this->messages.push_back(message);
}