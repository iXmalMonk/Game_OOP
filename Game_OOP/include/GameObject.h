#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Main.h"

class Game;

class GameObject
{
public:
	enum class MessageType { SHOOT, DESTROY, MOVE };
	enum class Direction { UP, DOWN, LEFT, RIGHT, NONE };
	enum class GameObjectType { PLAYER, ENEMY, PROJECTILE, NONE };

	struct Message
	{
		Message(MessageType _messageType, GameObject* _gameObject) : move()
		{
			messageType = _messageType;
			gameObject = _gameObject;
		}

		Message(MessageType _messageType, GameObject* _gameObject, Vector2f _position)
		{
			messageType = _messageType;
			gameObject = _gameObject;
			move.position = _position;
		}

		MessageType messageType;
		GameObject* gameObject;

		union
		{
			struct
			{
				Vector2f position;
			} move;
		};
	};

protected:
	Vector2f position;
	Texture texture;
	Sprite sprite;
	int w, h;

	Direction direction;
	GameObjectType gameObjectType;

	static Game* instance;

public:
	GameObject();
	void sendMessageInGame(Message* _message);
	Sprite getSprite();
	void setPosition(Vector2f _position);
	Vector2f getPosition();
	float getX();
	float getY();
	void setDirection();
	Direction getDirection();
	int getW();
	int getH();
	GameObjectType getGameObjectType();

	virtual void update(float _time) = 0;
	virtual void receiveMessage(Message* _message) = 0;
};

#endif // !_GAMEOBJECT_H
