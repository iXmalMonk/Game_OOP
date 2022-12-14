#ifndef _GAMEWINDOW_H
#define _GAMEWINDOW_H

#include "..\Main.h"

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
	bool isOpen();
	float getTime();
	static GameWindow* getInstance();
	Vector2i getMousePositionRelativeAWindow();
	void clear();
	void close();
	void destroy();
	void display();
	void draw(const RectangleShape& _rectangleShape);
	void draw(const Sprite& _sprite);
	void draw(const Text& _text);
	void events();
	void updateTime();
};

#endif // !_GAMEWINDOW_H