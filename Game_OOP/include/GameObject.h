#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class GameObject
{
protected:
	Vector2f position;
	Texture texture;
	Sprite sprite;

public:
	virtual void update(float time) = 0;
	Sprite getSprite();
};

#endif // !_GAMEOBJECT_H
