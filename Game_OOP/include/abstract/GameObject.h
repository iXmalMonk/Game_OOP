#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "..\Main.h"

class GameObject
{
public:
	enum class Direction { UP,
		DOWN,
		LEFT,
		RIGHT,
		NONE };
	enum class GameObjectType { BRICKWALL,
		CONCRETEWALL,
		ENEMY,
		FLAG,
		FOREST,
		HEADQUARTERS,
		PLAYER,
		PROJECTILE,
		WATER };
	enum class MessageType { CREATE,
		DEALDAMAGE,
		DESTROY,
		EMPTY };
	struct Message
	{
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

		Message(GameObject* _gameObject,
			GameObjectType _gameObjectType,
			Vector2f _position,
			MessageType _messageType); // CREATE
		Message(GameObject* _gameObjectWho,
			GameObject* _gameObjectWhom,
			int _damage,
			MessageType _messageType); // DEALDAMAGE
		Message(GameObject* _gameObject,
			MessageType _messageType); // DESTROY or EMPTY
	};

private:
	bool destroyed;
	Direction direction;
	GameObjectType gameObjectType;
	int w;
	int h;
	Sprite sprite;

protected:
	Vector2f position;

	bool checkCollisionAABBWithGameObject(GameObject* _gameObject);
	void create(GameObjectType _gameObjectType,
		Vector2f _position);
	void destroy();
	void empty();
	void setDirection(Direction _direction);
	void setPositionInSprite(Vector2f _position);

public:
	GameObject(Direction _direction,
		GameObjectType _gameObjectType,
		int _w,
		int _h,
		Texture* _texture,
		Vector2f _position);
	Direction getDirection();
	GameObjectType getGameObjectType();
	int getW();
	int getH();
	Sprite getSprite();
	Vector2f getPosition();
	float getX();
	float getY();

	virtual void message(Message* _message) = 0;
	virtual void update(float _time) = 0;
};

#endif // !_GAMEOBJECT_H