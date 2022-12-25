#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Main.h"

class GameObject
{
public:
	enum class Direction { UP, DOWN, LEFT, RIGHT, NONE };
	enum class GameObjectType { BRICKWALL, CONCRETEWALL, ENEMY, FLAG, FOREST, HEADQUARTERS, PLAYER, PROJECTILE, WATER, NONE };
	enum class CollisionSide { TOP, BOTTOM, LEFT, RIGHT, NONE };
	struct Collision
	{
		bool collided;
		CollisionSide collisionSide;
		Vector2f position;

		string side;

		Collision(bool _collided, CollisionSide _collisionSide, Vector2f _position, string _side)
		{
			collided = _collided;
			collisionSide = _collisionSide;
			position = _position;

			side = _side;
		}
	};
	enum class MessageType { CREATE, DEALDAMAGE, DESTROY, EMPTY };
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

		Message(GameObject* _gameObject, GameObjectType _gameObjectType, Vector2f _position, MessageType _messageType); // CREATE
		Message(GameObject* _gameObjectWho, GameObject* _gameObjectWhom, int _damage, MessageType _messageType); // DEALDAMAGE
		Message(GameObject* _gameObject, MessageType _messageType); // DESTROY or EMPTY
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
	Vector2f position;

	bool checkCollisionWithGameObject(GameObject* _gameObject);
	Collision collision(GameObject* _gameObject)
	{
		float topA = position.y;
		float bottomA = position.y + getH();
		float leftA = position.x;
		float rightA = position.x + getW();

		float topB = _gameObject->position.y;
		float bottomB = _gameObject->position.y + _gameObject->getH();
		float leftB = _gameObject->position.x;
		float rightB = _gameObject->position.x + _gameObject->getW();

		if (topA < bottomB and
			bottomA > topB and
			leftA < rightB and
			rightA > leftB)
		{
			switch (direction)
			{
			case Direction::UP:
				if (0 <= rightA - leftB and rightA - leftB < COLLISION_RANGE)
					return Collision(true, CollisionSide::TOP, Vector2f(leftB - getW(), bottomB), "TOP");
				else if (0 <= rightB - leftA and rightB - leftA < COLLISION_RANGE)
					return Collision(true, CollisionSide::TOP, Vector2f(rightB, bottomB), "TOP");
				else
					return Collision(true, CollisionSide::TOP, Vector2f(position.x, bottomB), "TOP");
				break;
			case Direction::DOWN:
				if (0 <= rightA - leftB and rightA - leftB < COLLISION_RANGE)
					return Collision(true, CollisionSide::BOTTOM, Vector2f(leftB - getW(), topB - getH()), "BOTTOM");
				else if (0 <= rightB - leftA and rightB - leftA < COLLISION_RANGE)
					return Collision(true, CollisionSide::BOTTOM, Vector2f(rightB, topB - getH()), "BOTTOM");
				else
					return Collision(true, CollisionSide::BOTTOM, Vector2f(position.x, topB - getH()), "BOTTOM");
				break;
			case Direction::LEFT:
				if (0 <= bottomA - topB and bottomA - topB < COLLISION_RANGE)
					return Collision(true, CollisionSide::LEFT, Vector2f(rightB, topB - getH()), "LEFT");
				else if (0 <= bottomB - topA and bottomB - topA < COLLISION_RANGE)
					return Collision(true, CollisionSide::LEFT, Vector2f(rightB, bottomB), "LEFT");
				else
					return Collision(true, CollisionSide::LEFT, Vector2f(rightB, position.y), "LEFT");
				break;
			case Direction::RIGHT:
				if (0 <= bottomA - topB and bottomA - topB < COLLISION_RANGE)
					return Collision(true, CollisionSide::RIGHT, Vector2f(leftB - getW(), topB - getH()), "RIGHT");
				else if (0 <= bottomB - topA and bottomB - topA < COLLISION_RANGE)
					return Collision(true, CollisionSide::RIGHT, Vector2f(leftB - getW(), bottomB), "RIGHT");
				else
					return Collision(true, CollisionSide::RIGHT, Vector2f(leftB - getW(), position.y), "RIGHT");
				break;
			}
		}

		return Collision(false, CollisionSide::NONE, Vector2f(0, 0), "NONE");
	}
	void create(GameObjectType _gameObjectType, Vector2f _position);
	void destroy();
	void empty();
	void setDirection(Direction _direction);
	void setPositionInSprite(Vector2f _position);

public:
	GameObject(const char* _filename, Direction _direction, GameObjectType _gameObjectType, int _w, int _h, Vector2f _position);
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