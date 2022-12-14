#include "..\..\include\abstract\Tank.h"
#include "..\..\include\utilts\Console.h"
#include "..\..\include\abstract\StaticObject.h"

bool Tank::guiltyOfCollidingWithAnotherTank(GameObject* _gameObject)
{
	float topThis = position.y;
	float bottomThis = position.y + getH();
	float leftThis = position.x;
	float rightThis = position.x + getW();
	float topGO = _gameObject->getY();
	float bottomGO = _gameObject->getY() + _gameObject->getH();
	float leftGO = _gameObject->getX();
	float rightGO = _gameObject->getX() + _gameObject->getW();
	switch (getDirection())
	{
	case Direction::UP:
		if (_gameObject->getDirection() == Direction::DOWN)
			return true;
		else if (-TANK_COLLISION_RANGE <= topThis - bottomGO and
			topThis - bottomGO <= TANK_COLLISION_RANGE)
			return true;
		break;
	case Direction::DOWN:
		if (_gameObject->getDirection() == Direction::UP)
			return true;
		else if (-TANK_COLLISION_RANGE <= topGO - bottomThis and
			topGO - bottomThis <= TANK_COLLISION_RANGE)
			return true;
		break;
	case Direction::LEFT:
		if (_gameObject->getDirection() == Direction::RIGHT)
			return true;
		else if (-TANK_COLLISION_RANGE <= leftThis - rightGO and
			leftThis - rightGO <= TANK_COLLISION_RANGE)
			return true;
		break;
	case Direction::RIGHT:
		if (_gameObject->getDirection() == Direction::LEFT)
			return true;
		else if (-TANK_COLLISION_RANGE <= leftGO - rightThis and
			leftGO - rightThis <= TANK_COLLISION_RANGE)
			return true;
		break;
	}
	return false;
}

bool Tank::isDead()
{
	return healthPoints <= 0 ? true : false;
}

Tank::Tank(Direction _direction, float _velocity, GameObjectType _gameObjectType, Texture* _texture, Vector2f _position) :
	DynamicObject(_direction,
		_velocity,
		_gameObjectType,
		TEXTURE_WIDTH_AND_HEIGHT_64,
		TEXTURE_WIDTH_AND_HEIGHT_64,
		_texture,
		_position)
{
	cooldownMaxTimeForShooting = TANK_MAX_COOLDOWN_TIME_FOR_SHOOTING;
	cooldownTimeForShooting = 0;
	healthPoints = TANK_HEALTHPOINTS;
}

bool Tank::isReadyToShoot(float _time)
{
	cooldownTimeForShooting < cooldownMaxTimeForShooting ? cooldownTimeForShooting += _time : cooldownTimeForShooting = cooldownMaxTimeForShooting;
	return cooldownTimeForShooting >= cooldownMaxTimeForShooting ? true : false;
}

void Tank::message(Message* _message)
{
	if (isDealDamage(_message))
	{
		healthPoints -= _message->dealDamage.damage;
		if (isDead())
			destroyMessage();
	}
	else if (_message->messageType == MessageType::EMPTY and
		_message->gameObject->getGameObjectType() != GameObjectType::FOREST and
		_message->gameObject->getGameObjectType() != GameObjectType::PROJECTILE and
		_message->gameObject != this and
		isCollisionAABBWithGameObject(_message->gameObject))
	{
		if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL or
			_message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL or
			_message->gameObject->getGameObjectType() == GameObjectType::FLAG or
			_message->gameObject->getGameObjectType() == GameObjectType::HEADQUARTERS or
			_message->gameObject->getGameObjectType() == GameObjectType::WATER)
		{
			auto positionOfADynamicObjectRelativeToAStaticObject = StaticObject::getPositionOfADynamicObjectRelativeToAStaticObjectAfterCollision(this,
				_message->gameObject);
			position.x = positionOfADynamicObjectRelativeToAStaticObject.x;
			position.y = positionOfADynamicObjectRelativeToAStaticObject.y;
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY or
			_message->gameObject->getGameObjectType() == GameObjectType::PLAYER)
		{
			if (guiltyOfCollidingWithAnotherTank(_message->gameObject))
				position.x -= dx;
				position.y -= dy;
		}
		setPositionInSprite(position);
	}
}

void Tank::shoot()
{
	if (cooldownTimeForShooting >= cooldownMaxTimeForShooting)
	{
		createMessage(GameObjectType::PROJECTILE,
			getPosition());
		cooldownTimeForShooting = 0;
	}
}