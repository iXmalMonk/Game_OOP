#ifndef _GAMEMENU_H
#define _GAMEMENU_H

#include "..\Main.h"

class GameMenu
{
private:
	static GameMenu* instance;

	bool gameLoop;
	bool menuLoop;
	RectangleShape* rectangleShape;

	GameMenu();
	bool isCollisionMouseWithText(const Text& _text);
	bool isMouseOnText(Text& _text);
	bool onLeftClick();

public:
	bool isGame();
	bool isMenu();
	static GameMenu* getInstance();
	void destroy();
	void drawGame();
	void drawMenu();
	void updateGame();
	void updateMenu();
};

#endif // !_GAMEMENU_H