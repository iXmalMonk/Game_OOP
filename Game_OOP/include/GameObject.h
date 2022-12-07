#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Main.h"

class Game;

class GameObject
{
public:
	enum class MessageType { SHOOT, DESTROY };
	enum class Direction { UP, DOWN, LEFT, RIGHT, NONE };
	
	struct Message
	{
		Message(MessageType _messageType, GameObject* _gameObject)
		{
			messageType = _messageType;
			gameObject = _gameObject;
		}

		MessageType messageType;
		GameObject* gameObject;
	};

protected:
	Vector2f position;
	Texture texture;
	Sprite sprite;
	int w, h;

	Direction direction;

	static Game* instance;

public:
	GameObject();
	void sendMessage(Message* _message);
	Sprite getSprite();
	void setPosition(Vector2f _position);
	Vector2f getPosition();
	void setDirection();
	Direction getDirection();
	int getW();
	int getH();

	virtual void update(float _time) = 0;
};

#endif // !_GAMEOBJECT_H
