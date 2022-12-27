#ifndef _GAMEWINDOW_H
#define _GAMEWINDOW_H

#include "Main.h"

class GameWindow
{
private:
	static GameWindow* instance;

	Clock* clock;
	Event* event;
	float time;
	RenderWindow* renderWindow;

	GameWindow();
	~GameWindow();

public:
	void clear();
	void destroy();
	void display();
	void draw(Sprite _sprite);
	void events();
	static GameWindow* getInstance();
	float getTime();
	bool isOpen();
	void updateTime();
};

#endif // !_GAMEWINDOW_H