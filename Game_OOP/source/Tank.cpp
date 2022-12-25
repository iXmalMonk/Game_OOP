#include "..\include\Tank.h"
#include "..\include\Game.h"

Tank::Tank(const char* _filename, Direction _direction, float _velocity, GameObjectType _gameObjectType, Vector2f _position) : DynamicObject(_filename, _direction, _velocity, _gameObjectType, TANK_W, TANK_H, _position)
{
	healthPoints = TANK_HEALTHPOINTS;
	cooldown = TANK_COOLDOWN;
	cooldownTime = cooldown;
}

void Tank::alive()
{
	if (healthPoints <= 0)
	{
		destroy();
		if (MESSAGES_DEBUG_IN_TANK)
			cout << "Tank destroyed" << endl;
	}
}

int Tank::getHealthPoints()
{
	return healthPoints;
}

void Tank::message(Message* _message)
{
	if (_message->messageType == MessageType::DEALDAMAGE and
		_message->dealDamage.gameObject == this)
	{
		setHealthPoints(getHealthPoints() - _message->dealDamage.damage);
		if (MESSAGES_DEBUG_IN_ENEMY)
			cout << "Enemy HP: " << getHealthPoints() << endl;
		alive();
	}
	else if (_message->messageType == MessageType::EMPTY and
		_message->gameObject->getGameObjectType() != GameObjectType::FOREST and
		_message->gameObject->getGameObjectType() != GameObjectType::PROJECTILE and
		_message->gameObject != this)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL or
				_message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL or
				_message->gameObject->getGameObjectType() == GameObjectType::FLAG or
				_message->gameObject->getGameObjectType() == GameObjectType::HEADQUARTERS or
				_message->gameObject->getGameObjectType() == GameObjectType::WATER)
			{
				Collision temporary = collision(_message->gameObject);
				cout << "Collision side: " << temporary.side << endl;
				switch (temporary.collisionSide)
				{
				case CollisionSide::TOP:
					position.x = temporary.position.x;
					position.y = temporary.position.y;
					break;
				case CollisionSide::BOTTOM:
					position.x = temporary.position.x;
					position.y = temporary.position.y;
					break;
				case CollisionSide::LEFT:
					position.x = temporary.position.x;
					position.y = temporary.position.y;
					break;
				case CollisionSide::RIGHT:
					position.x = temporary.position.x;
					position.y = temporary.position.y;
					break;
				}
			}
		else
			{
				position.x -= dx;
				position.y -= dy;
			}
			setPositionInSprite(position);
		}
	}
}

bool Tank::readyToShoot(float _time)
{
	cooldown > cooldownTime ? cooldownTime += _time : cooldownTime = cooldown;
	return cooldown <= cooldownTime ? true : false;
}

void Tank::setHealthPoints(int _healthPoints)
{
	healthPoints = _healthPoints;
}

void Tank::shoot()
{
	if (cooldown <= cooldownTime)
	{
		create(GameObjectType::PROJECTILE, getPosition());
		cooldownTime = 0;
	}
}