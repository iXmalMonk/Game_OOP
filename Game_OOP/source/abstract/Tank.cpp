#include "..\..\include\abstract\Tank.h"
#include "..\..\include\utilts\Console.h"
#include "..\..\include\abstract\StaticObject.h"

void Tank::alive()
{
	if (healthPoints <= 0)
		destroy();
}

bool Tank::guiltyOfCollidingWithAnotherTank(GameObject* _gameObject)
{
	float topA = position.y;
	float bottomA = position.y + getH();
	float leftA = position.x;
	float rightA = position.x + getW();
	float topB = _gameObject->getY();
	float bottomB = _gameObject->getY() + _gameObject->getH();
	float leftB = _gameObject->getX();
	float rightB = _gameObject->getX() + _gameObject->getW();
	switch (getDirection())
	{
	case Direction::UP:
		if (_gameObject->getDirection() == Direction::DOWN)
			return true;
		else if (-COLLISION_RANGE_FOR_TANK <= topA - bottomB and
			topA - bottomB <= COLLISION_RANGE_FOR_TANK)
			return true;
		break;
	case Direction::DOWN:
		if (_gameObject->getDirection() == Direction::UP)
			return true;
		else if (-COLLISION_RANGE_FOR_TANK <= topB - bottomA and
			topB - bottomA <= COLLISION_RANGE_FOR_TANK)
			return true;
		break;
	case Direction::LEFT:
		if (_gameObject->getDirection() == Direction::RIGHT)
			return true;
		else if (-COLLISION_RANGE_FOR_TANK <= leftA - rightB and
			leftA - rightB <= COLLISION_RANGE_FOR_TANK)
			return true;
		break;
	case Direction::RIGHT:
		if (_gameObject->getDirection() == Direction::LEFT)
			return true;
		else if (-COLLISION_RANGE_FOR_TANK <= leftB - rightA and
			leftB - rightA <= COLLISION_RANGE_FOR_TANK)
			return true;
		break;
	}
	return false;
}

int Tank::getHealthPoints()
{
	return healthPoints;
}

void Tank::setHealthPoints(int _healthPoints)
{
	healthPoints = _healthPoints;
}

Tank::Tank(Direction _direction, float _velocity, GameObjectType _gameObjectType, Texture* _texture, Vector2f _position) :
	DynamicObject(_direction,
		_velocity,
		_gameObjectType,
		TANK_W,
		TANK_H,
		_texture,
		_position)
{
	healthPoints = TANK_HEALTHPOINTS;
	cooldownMaxTimeForShooting = TANK_COOLDOWN_MAX_TIME_FOR_SHOOTING;
	cooldownTimeForShooting = 0;
}

void Tank::message(Message* _message)
{
	if (_message->messageType == MessageType::DEALDAMAGE and
		_message->dealDamage.gameObject == this)
	{
		setHealthPoints(getHealthPoints() - _message->dealDamage.damage);
		alive();
	}
	else if (_message->messageType == MessageType::EMPTY and
		_message->gameObject->getGameObjectType() != GameObjectType::FOREST and
		_message->gameObject->getGameObjectType() != GameObjectType::PROJECTILE and
		_message->gameObject != this and checkCollisionAABBWithGameObject(_message->gameObject))
	{
		if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL or
			_message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL or
			_message->gameObject->getGameObjectType() == GameObjectType::FLAG or
			_message->gameObject->getGameObjectType() == GameObjectType::HEADQUARTERS or
			_message->gameObject->getGameObjectType() == GameObjectType::WATER)
		{
			auto positionOfADynamicObjectRelativeToAStaticObject = StaticObject::findPositionOfADynamicObjectRelativeToAStaticObjectAfterCollision(this,
				_message->gameObject);
			position.x = positionOfADynamicObjectRelativeToAStaticObject.x;
			position.y = positionOfADynamicObjectRelativeToAStaticObject.y;
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY or
			_message->gameObject->getGameObjectType() == GameObjectType::PLAYER)
		{
			if (guiltyOfCollidingWithAnotherTank(_message->gameObject))
			{
				position.x -= dx;
				position.y -= dy;
			}
		}
		setPositionInSprite(position);
	}
}

bool Tank::readyToShoot(float _time)
{
	cooldownMaxTimeForShooting > cooldownTimeForShooting ? cooldownTimeForShooting += _time : cooldownTimeForShooting = cooldownMaxTimeForShooting;
	return cooldownMaxTimeForShooting <= cooldownTimeForShooting ? true : false;
}

void Tank::shoot()
{
	if (cooldownMaxTimeForShooting <= cooldownTimeForShooting)
	{
		create(GameObjectType::PROJECTILE,
			getPosition());
		cooldownTimeForShooting = 0;
	}
}