#ifndef _GAMEWINDOW_H
#define _GAMEWINDOW_H

#include "Main.h"

class GameWindow
{
private:
	Clock* clock;
	Event* event;
	float time;
	RenderWindow* renderWindow;

public:
	GameWindow();
	~GameWindow();
	void clear();
	void create();
	void display();
	void draw(Sprite _sprite);
	void events();
	float getTime();
	bool isOpen();
	void updateTime();
};

#endif // !_GAMEWINDOW_H