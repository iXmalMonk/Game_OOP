#include "..\..\include\utilts\GameMenu.h"
#include "..\..\include\utilts\GameResources.h"
#include "..\..\include\utilts\GameWindow.h"

GameMenu* GameMenu::instance = nullptr;

GameMenu::GameMenu()
{
	gameLoop = false;
	menuLoop = true;
	rectangleShape = new RectangleShape(Vector2f(MAP_BLOCK * MAP_SIZE, MAP_BLOCK * MAP_SIZE));
	rectangleShape->setPosition(Vector2f(MAP_LEFT_X, MAP_UP_Y));
	rectangleShape->setFillColor(Color::Black);
}

bool GameMenu::checkLeftClick()
{
	static bool flag = true;
	if (Mouse::isButtonPressed(Mouse::Button::Left) and
		flag)
	{
		flag = false;
		return true;
	}
	else if (!Mouse::isButtonPressed(Mouse::Button::Left) and
		!flag)
	{
		flag = true;
		return false;
	}
	else
		return false;
}

bool GameMenu::checkCollisionMouseWithText(const Text& _text)
{
	auto mousePosition = Mouse::getPosition(*GameWindow::getInstance()->getRenderWindow());
	auto textPosition = _text.getPosition();
	return (textPosition.x + _text.getLocalBounds().width) >= mousePosition.x and
		mousePosition.x >= textPosition.x and
		(textPosition.y + _text.getLocalBounds().height * 2) >= mousePosition.y and
		mousePosition.y >= textPosition.y + _text.getLocalBounds().height;
}

bool GameMenu::isMouseOnText(Text& _text)
{
	if (checkCollisionMouseWithText(_text))
	{
		_text.setFillColor(Color::Red);
		return true;
	}
	else
	{
		_text.setFillColor(Color::White);
		return false;
	}
}

void GameMenu::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void GameMenu::drawGame()
{
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::MENU));
	GameWindow::getInstance()->draw(*rectangleShape);
}

void GameMenu::drawMenu()
{
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::EXIT));
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::PLAY));
}

GameMenu* GameMenu::getInstance()
{
	if (!instance)
		instance = new GameMenu;
	return instance;
}

bool GameMenu::isGame()
{
	return gameLoop;
}

bool GameMenu::isMenu()
{
	return menuLoop;
}

void GameMenu::updateGame()
{
	isMouseOnText(*GameResources::getInstance()->getText(GameResources::TextType::MENU));
	if (checkLeftClick() and
		checkCollisionMouseWithText(*GameResources::getInstance()->getText(GameResources::TextType::MENU)))
	{
		gameLoop = false;
		menuLoop = true;
	}
}

void GameMenu::updateMenu()
{
	isMouseOnText(*GameResources::getInstance()->getText(GameResources::TextType::EXIT));
	isMouseOnText(*GameResources::getInstance()->getText(GameResources::TextType::PLAY));
	if (checkLeftClick())
	{
		if (checkCollisionMouseWithText(*GameResources::getInstance()->getText(GameResources::TextType::EXIT)))
			GameWindow::getInstance()->close();
		else if (checkCollisionMouseWithText(*GameResources::getInstance()->getText(GameResources::TextType::PLAY)))
		{
			menuLoop = false;
			gameLoop = true;
		}
	}
}