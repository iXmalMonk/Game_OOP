#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Main.h"

class Game;

class GameObject
{
public:
	enum class Direction { UP, DOWN, LEFT, RIGHT, NONE };
	enum class GameObjectType { BRICKWALL, CONCRETEWALL, ENEMY, FOREST, PLAYER, PROJECTILE, WATER, NONE };
	enum class MessageType { CREATE, DEALDAMAGE, DESTROY, MOVE, SHOOT };

	struct Message
	{
		Message(MessageType _messageType, GameObject* _gameObjectWho, GameObject* _gameObjectWhom, int _damage) // DEALDAMAGE
		{
			messageType = _messageType;
			gameObject = _gameObjectWho;
			dealDamage.gameObject = _gameObjectWhom;
			dealDamage.damage = _damage;
		}

		Message(MessageType _messageType, GameObject* _gameObject, Vector2f _position) // MOVE
		{
			messageType = _messageType;
			gameObject = _gameObject;
			move.position = _position;
		}

		Message(MessageType _messageType, GameObject* _gameObject) // SHOOT
		{
			messageType = _messageType;
			gameObject = _gameObject;
		}

		GameObject* gameObject;
		MessageType messageType;

		union
		{
			struct
			{
				GameObjectType gameObjectType;
				Vector2f position;
			} create;

			struct
			{
				GameObject* gameObject;
				int damage;
			} dealDamage;

			struct
			{
				Vector2f position;
			} move;
		};
	};

private:
	bool destroyed;

protected:
	Direction direction;
	GameObjectType gameObjectType;
	int w;
	int h;
	Sprite sprite;
	static Game* game;
	Texture texture;
	Vector2f position;

	bool checkCollisionWithGameObject(GameObject* _gameObject);
	void dealDamage(GameObject* _gameObject, int _damage);
	void destroy();
	void move(Vector2f _position);
	void setDirection();
	void setPosition(Vector2f _position);

public:
	GameObject();
	Direction getDirection();
	float getX();
	float getY();
	GameObjectType getGameObjectType();
	int getW();
	int getH();
	Sprite getSprite();
	Vector2f getPosition();
	void sendMessageInGame(Message* _message);

	virtual void receiveMessage(Message* _message) = 0;
	virtual void update(float _time) = 0;
};

#endif // !_GAMEOBJECT_H