#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Main.h"

class Game;

class GameObject
{
public:
	enum class Direction { UP, DOWN, LEFT, RIGHT, NONE };
	enum class GameObjectType { BRICKWALL, CONCRETEWALL, ENEMY, FOREST, PLAYER, PROJECTILE, WATER, NONE };
	enum class MessageType { CREATE, DEALDAMAGE, DESTROY, EMPTY, SHOOT };

	struct Message
	{
		Message(MessageType _messageType, GameObject* _gameObjectWho, GameObject* _gameObjectWhom, int _damage) // DEALDAMAGE
		{
			messageType = _messageType;
			gameObject = _gameObjectWho;
			dealDamage.gameObject = _gameObjectWhom;
			dealDamage.damage = _damage;
		}

		Message(MessageType _messageType, GameObject* _gameObject) // DESTROY or EMPTY
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
		};
	};

private:
	bool destroyed;
	Direction direction;
	GameObjectType gameObjectType;
	int w;
	int h;
	Texture texture;
	Sprite sprite;

protected:
	static Game* game;
	Vector2f position;

	bool checkCollisionWithGameObject(GameObject* _gameObject);
	void destroy();
	void empty();
	void setDirection(Direction _direction);
	void setPosition(Vector2f _position);

public:
	GameObject(Direction _direction, GameObjectType _gameObjectType, int _w, int _h, const char* _filename, Vector2f _position);
	Direction getDirection();
	GameObjectType getGameObjectType();
	int getW();
	int getH();
	Sprite getSprite();
	Vector2f getPosition();
	void sendMessageInGame(Message* _message);
	float getX();
	float getY();

	virtual void receiveMessage(Message* _message) = 0;
	virtual void update(float _time) = 0;
};

#endif // !_GAMEOBJECT_H