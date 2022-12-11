#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Main.h"

class Game;

class GameObject
{
public:
	enum class MessageType { SHOOT, DESTROY, DEALDAMAGE, MOVE };
	enum class Direction { UP, DOWN, LEFT, RIGHT, NONE };
	enum class GameObjectType { PLAYER, ENEMY, PROJECTILE, BRICKWALL, WATER, CONCRETEWALL, FOREST, NONE };

	struct Message
	{
		Message(MessageType _messageType, GameObject* _gameObject)
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

		Message(MessageType _messageType, GameObject* _gameObjectWho, GameObject* _gameObjectWhom, int _damage)
		{
			messageType = _messageType;
			gameObject = _gameObjectWho;
			dealDamage.gameObject = _gameObjectWhom;
			dealDamage.damage = _damage;
		}

		MessageType messageType;
		GameObject* gameObject;

		union
		{
			struct
			{
				int damage;
				GameObject* gameObject;
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
	Vector2f position;
	Texture texture;
	Sprite sprite;
	int w, h;

	Direction direction;
	GameObjectType gameObjectType;

	static Game* instance;

	void setPosition(Vector2f _position);
	void setDirection();
	bool checkCollisionWithGameObject(GameObject* _gameObject);
	void destroy();
	void dealDamage(GameObject* _gameObject, int _damage);
	void move(Vector2f _position);
public:
	GameObject();
	void sendMessageInGame(Message* _message);
	Vector2f getPosition();
	Sprite getSprite();
	float getX();
	float getY();
	Direction getDirection();
	int getW();
	int getH();
	GameObjectType getGameObjectType();

	virtual void update(float _time) = 0;
	virtual void receiveMessage(Message* _message) = 0;
};

#endif // !_GAMEOBJECT_H