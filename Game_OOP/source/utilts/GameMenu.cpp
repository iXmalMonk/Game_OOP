#include "..\..\include\utilts\GameMenu.h"
#include "..\..\include\utilts\Game.h"
#include "..\..\include\utilts\GameController.h"
#include "..\..\include\utilts\GameResources.h"
#include "..\..\include\utilts\GameWindow.h"

GameMenu* GameMenu::instance = nullptr;

GameMenu::GameMenu()
{
	gameLoop = false;
	menuLoop = true;
	levelFlagForDrawing = false;
	drawingTimeForDefeatOrVictory = 0;
	drawingTimeForLevel = 0;
	maxDrawingTimeForDefeatOrVictory = GAMEMENU_MAX_DRAWING_TIME_FOR_LOSE_OR_WIN;
	maxDrawingTimeForLevel = GAMEMENU_MAX_DRAWING_TIME_FOR_LEVEL;
	rectangleShape = new RectangleShape(Vector2f(MAP_BLOCK * MAP_SIZE, MAP_BLOCK * MAP_SIZE));
	rectangleShape->setPosition(Vector2f(MAP_LEFT, MAP_UP));
	rectangleShape->setFillColor(COLOR_BLACK);
}

bool GameMenu::isCollisionMouseWithText(const Text& _text)
{
	auto mousePosition = GameWindow::getInstance()->getMousePositionRelativeAWindow();
	auto textPosition = _text.getPosition();
	return (textPosition.x + _text.getLocalBounds().width) >= mousePosition.x and
		mousePosition.x >= textPosition.x and
		(textPosition.y + _text.getLocalBounds().height * 2) >= mousePosition.y and
		mousePosition.y >= textPosition.y + _text.getLocalBounds().height;
}

bool GameMenu::isMouseOnText(Text& _text)
{
	if (isCollisionMouseWithText(_text))
	{
		_text.setFillColor(COLOR_RED);
		return true;
	}
	else
	{
		_text.setFillColor(COLOR_WHITE);
		return false;
	}
}

bool GameMenu::onLeftClick()
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

bool GameMenu::isGame()
{
	return gameLoop;
}

bool GameMenu::isMenu()
{
	return menuLoop;
}

bool GameMenu::isLevel()
{
	return levelFlagForDrawing;
}

GameMenu* GameMenu::getInstance()
{
	if (!instance)
		instance = new GameMenu;
	return instance;
}

void GameMenu::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void GameMenu::drawGameFirstLayer()
{
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::ENEMY));
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getTextForCounters(GameResources::TextTypeForCounters::ENEMY));
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::MENU));
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::PLAYER));
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getTextForCounters(GameResources::TextTypeForCounters::PLAYER));
	GameWindow::getInstance()->draw(*rectangleShape);
}

void GameMenu::drawGameLastLayer()
{
	if (GameController::getInstance()->isLose())
		GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::LOSE));
	else if (GameController::getInstance()->isWin())
		GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::WIN));
}

void GameMenu::drawGameLevel()
{
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::LEVEL));
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getTextForCounters(GameResources::TextTypeForCounters::LEVEL));
}

void GameMenu::drawMenu()
{
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::CONTINUE));
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::EXIT));
	GameWindow::getInstance()->draw(*GameResources::getInstance()->getText(GameResources::TextType::NEW_GAME));
}

void GameMenu::updateGame(float _time)
{
	if (!levelFlagForDrawing)
	{
		isMouseOnText(*GameResources::getInstance()->getText(GameResources::TextType::MENU));
		if (onLeftClick() and
			isCollisionMouseWithText(*GameResources::getInstance()->getText(GameResources::TextType::MENU)))
		{
			drawingTimeForDefeatOrVictory = 0;
			gameLoop = false;
			menuLoop = true;
		}
		if ((GameController::getInstance()->isLose() or
			GameController::getInstance()->isWin()) and
			drawingTimeForDefeatOrVictory < maxDrawingTimeForDefeatOrVictory)
			drawingTimeForDefeatOrVictory += _time;
		else if (drawingTimeForDefeatOrVictory >= maxDrawingTimeForDefeatOrVictory)
		{
			drawingTimeForDefeatOrVictory = 0;
			gameLoop = false;
			menuLoop = true;
		}
	}
	if (GameController::getInstance()->isNewLevel())
		levelFlagForDrawing = true;
	if (levelFlagForDrawing and
		drawingTimeForLevel < maxDrawingTimeForLevel)
		drawingTimeForLevel += _time;
	else if (drawingTimeForLevel >= maxDrawingTimeForLevel)
	{
		drawingTimeForLevel = 0;
		levelFlagForDrawing = false;
	}
}

void GameMenu::updateMenu()
{
	if (GameController::getInstance()->isContinue())
	{
		GameResources::getInstance()->getText(GameResources::TextType::CONTINUE)->setFillColor(COLOR_WHITE);
		isMouseOnText(*GameResources::getInstance()->getText(GameResources::TextType::CONTINUE));
	}
	else
		GameResources::getInstance()->getText(GameResources::TextType::CONTINUE)->setFillColor(COLOR_WHITE_TRANSPARENT);
	isMouseOnText(*GameResources::getInstance()->getText(GameResources::TextType::EXIT));
	isMouseOnText(*GameResources::getInstance()->getText(GameResources::TextType::NEW_GAME));
	if (onLeftClick())
	{
		if (isCollisionMouseWithText(*GameResources::getInstance()->getText(GameResources::TextType::CONTINUE)) and
			GameController::getInstance()->isContinue())
		{
			menuLoop = false;
			gameLoop = true;
		}
		else if (isCollisionMouseWithText(*GameResources::getInstance()->getText(GameResources::TextType::EXIT)))
			GameWindow::getInstance()->close();
		else if (isCollisionMouseWithText(*GameResources::getInstance()->getText(GameResources::TextType::NEW_GAME)))
		{
			menuLoop = false;
			gameLoop = true;
			Game::getInstance()->message(new GameObject::Message(NULL,
				GameObject::MessageType::DESTROY_ALL));
		}
	}
}