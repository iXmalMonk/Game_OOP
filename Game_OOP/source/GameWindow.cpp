#include "..\include\GameWindow.h"

GameWindow::GameWindow() : clock(nullptr), event(nullptr), renderWindow(nullptr), time(0)
{
	clock = new Clock;
	event = new Event;
	renderWindow = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
	renderWindow->setFramerateLimit(WINDOW_FPS);
}

GameWindow::~GameWindow()
{
	delete clock;
	delete event;
	delete renderWindow;
}

void GameWindow::events()
{
	while (renderWindow->pollEvent(*event))
		if ((*event).type == Event::Closed)
			renderWindow->close();
}

void GameWindow::updateTime()
{
	time = clock->getElapsedTime().asMicroseconds() / TIME_COEFFICIENT;
	clock->restart();
}

float GameWindow::getTime()
{
	return time;
}

void GameWindow::clear()
{
	renderWindow->clear();
}

void GameWindow::draw(Sprite _sprite)
{
	renderWindow->draw(_sprite);
}

void GameWindow::display()
{
	renderWindow->display();
}

bool GameWindow::isOpen()
{
	return renderWindow->isOpen();
}

void GameWindow::create()
{
	renderWindow->create(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
	renderWindow->setFramerateLimit(WINDOW_FPS);
}
