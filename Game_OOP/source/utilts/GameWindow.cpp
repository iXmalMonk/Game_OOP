#include "..\..\include\utilts\GameWindow.h"
#include "..\..\include\utilts\GameMenu.h"

GameWindow* GameWindow::instance = nullptr;

GameWindow::GameWindow()
{
	clock = new Clock;
	event = new Event;
	time = 0;
	renderWindow = new RenderWindow(VideoMode(WINDOW_W,
		WINDOW_H),
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

bool GameWindow::isOpen()
{
	return renderWindow->isOpen();
}

float GameWindow::getTime()
{
	return time;
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

void GameWindow::clear()
{
	renderWindow->clear(Color(GAMEWINDOW_COLOR_FOR_BACKGROUND_R,
		GAMEWINDOW_COLOR_FOR_BACKGROUND_G,
		GAMEWINDOW_COLOR_FOR_BACKGROUND_B,
		255));
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

void GameWindow::updateTime()
{
	time = clock->restart().asSeconds();
}