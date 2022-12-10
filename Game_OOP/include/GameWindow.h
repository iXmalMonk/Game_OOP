#ifndef _GAMEWINDOW_H
#define _GAMEWINDOW_H

#include "Main.h"

class GameWindow
{
private:
	Clock* clock;
	Event* event;
	RenderWindow* renderWindow;

	float time;

public:
	GameWindow();
	~GameWindow();
	void events();
	void updateTime();
	float getTime();
	void clear();
	void draw(Sprite _sprite);
	void display();
	bool isOpen();
	void create();
};

#endif // !_GAMEWINDOW_H