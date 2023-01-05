#ifndef _GAMEMENU_H
#define _GAMEMENU_H

#include "..\Main.h"

class GameMenu
{
private:
	static GameMenu* instance;

	bool gameLoop;
	bool menuLoop;
	bool levelFlagForDrawing;
	float drawingTimeForDefeatOrVictory;
	float drawingTimeForLevel;
	float maxDrawingTimeForDefeatOrVictory;
	float maxDrawingTimeForLevel;
	RectangleShape* rectangleShape;

	GameMenu();
	bool isCollisionMouseWithText(const Text& _text);
	bool isMouseOnText(Text& _text);
	bool onLeftClick();

public:
	bool isGame();
	bool isMenu();
	bool isLevel();
	static GameMenu* getInstance();
	void destroy();
	void drawGameFirstLayer();
	void drawGameLastLayer();
	void drawGameLevel();
	void drawMenu();
	void updateGame(float _time);
	void updateMenu();
};

#endif // !_GAMEMENU_H