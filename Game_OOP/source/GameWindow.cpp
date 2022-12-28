#include "..\include\GameWindow.h"

GameWindow* GameWindow::instance = nullptr;

GameWindow::GameWindow()
{
	clock = new Clock;
	event = new Event;
	time = 0;
	renderWindow = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H),
		WINDOW_TITLE,
		Style::None);
	renderWindow->setFramerateLimit(WINDOW_FPS);
}

GameWindow::~GameWindow()
{
	delete clock;
	delete event;
	delete renderWindow;
}

void GameWindow::clear()
{
	renderWindow->clear();
}

void GameWindow::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void GameWindow::display()
{
	renderWindow->display();
}

void GameWindow::draw(Sprite _sprite)
{
	renderWindow->draw(_sprite);
}

void GameWindow::events()
{
	while (renderWindow->pollEvent(*event))
		if (((*event).type == Event::Closed) or
			((*event).type == Event::KeyPressed and
				(*event).key.code == Keyboard::Escape))
			renderWindow->close();
}

GameWindow* GameWindow::getInstance()
{
	if (!instance)
		instance = new GameWindow;
	return instance;
}

float GameWindow::getTime()
{
	return time;
}

bool GameWindow::isOpen()
{
	return renderWindow->isOpen();
}

void GameWindow::updateTime()
{
	time = clock->restart().asSeconds();
}