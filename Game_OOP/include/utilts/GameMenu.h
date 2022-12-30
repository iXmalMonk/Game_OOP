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
	bool checkLeftClick();
	bool checkCollisionMouseWithText(const Text& _text);
	bool isMouseOnText(Text& _text);

public:
	void destroy();
	void drawGame();
	void drawMenu();
	static GameMenu* getInstance();
	bool isGame();
	bool isMenu();
	void updateGame();
	void updateMenu();
};

#endif // !_GAMEMENU_H