#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Main.h"

struct Game; //

class GameObject
{
public:
	struct Message
	{

	};

protected:
	Vector2f position;
	Texture texture;
	Sprite sprite;
	int w, h;

	static Game* instance; //

public:
	GameObject();
	void sendMessage(Message* _message);
	Sprite getSprite();
	void setPosition(Vector2f _position);

	virtual void update(float _time) = 0;
};

#endif // !_GAMEOBJECT_H
