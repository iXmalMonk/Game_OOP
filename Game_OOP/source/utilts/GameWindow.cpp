#include "..\..\include\utilts\GameWindow.h"
#include "..\..\include\utilts\GameMenu.h"

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
	renderWindow->clear(Color(50, 50, 50, 255));
}

void GameWindow::close()
{
	renderWindow->close();
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

void GameWindow::draw(const RectangleShape& _rectangleShape)
{
	renderWindow->draw(_rectangleShape);
}

void GameWindow::draw(const Sprite& _sprite)
{
	renderWindow->draw(_sprite);
}

void GameWindow::draw(const Text& _text)
{
	renderWindow->draw(_text);
}

void GameWindow::events()
{
	while (renderWindow->pollEvent(*event))
		if (event->key.code == Keyboard::Escape and
			GameMenu::getInstance()->isMenu())
			renderWindow->close();
}

GameWindow* GameWindow::getInstance()
{
	if (!instance)
		instance = new GameWindow;
	return instance;
}

Vector2i GameWindow::getMousePositionRelativeAWindow()
{
	return Mouse::getPosition(*renderWindow);
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