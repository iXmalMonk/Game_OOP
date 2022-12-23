#include "..\include\GameWindow.h"

GameWindow* GameWindow::instance = nullptr;

GameWindow::GameWindow()
{
	clock = new Clock;
	event = new Event;
	time = 0;
	renderWindow = new RenderWindow(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE, Style::Titlebar);
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

void GameWindow::create()
{
	renderWindow->create(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
	renderWindow->setFramerateLimit(WINDOW_FPS);
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
		if (((*event).type == Event::Closed) or ((*event).type == Event::KeyPressed and (*event).key.code == Keyboard::Escape))
			renderWindow->close();
}

float GameWindow::getTime()
{
	return time;
}

bool GameWindow::isOpen()
{
	return renderWindow->isOpen();
}

GameWindow* GameWindow::getInstance()
{
	if (!instance)
		instance = new GameWindow;

	return instance;
}

void GameWindow::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void GameWindow::updateTime()
{
	time = clock->getElapsedTime().asMicroseconds() / TIME_COEFFICIENT;
	clock->restart();
}