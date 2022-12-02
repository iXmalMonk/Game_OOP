#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Main.h"

using namespace sf;

class GameObject
{
protected:
	Vector2f position;
	Texture texture;
	Sprite sprite;
	int w, h;

public:
	virtual void update(float time) = 0;
	Sprite getSprite();
};

#endif // !_GAMEOBJECT_H
