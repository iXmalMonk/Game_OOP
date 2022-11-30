#ifndef _OBJECT_H
#define _OBJECT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Object
{
protected:
	double x, y;
	int w, h;
	String filename;
	Texture texture;
	Sprite sprite;
public:
	Object();
	virtual ~Object();

	virtual void update(double time) = 0;
	void draw();
};

#endif