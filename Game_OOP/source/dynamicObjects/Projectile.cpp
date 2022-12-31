#include "..\..\include\dynamicObjects\Projectile.h"
#include "..\..\include\utilts\Game.h"
#include "..\..\include\utilts\GameResources.h"

void Projectile::dealDamage(GameObject* _gameObject, int _damage)
{
	Game::getInstance()->message(new Message(this,
		_gameObject,
		_damage,
		MessageType::DEALDAMAGE));
}

Vector2f Projectile::getPositionForProjectile(Direction _direction, Vector2f _position)
{
	Vector2f temporary;
	switch (_direction)
	{
	case Direction::UP:
		temporary.x = float(_position.x + PROJECTILE_COEFFICIENT_X_FOR_UP);
		temporary.y = float(_position.y + PROJECTILE_COEFFICIENT_Y_FOR_UP);
		break;
	case Direction::DOWN:
		temporary.x = float(_position.x + PROJECTILE_COEFFICIENT_X_FOR_DOWN);
		temporary.y = float(_position.y + PROJECTILE_COEFFICIENT_Y_FOR_DOWN);
		break;
	case Direction::LEFT:
		temporary.x = float(_position.x + PROJECTILE_COEFFICIENT_X_FOR_LEFT);
		temporary.y = float(_position.y + PROJECTILE_COEFFICIENT_Y_FOR_LEFT);
		break;
	case Direction::RIGHT:
		temporary.x = float(_position.x + PROJECTILE_COEFFICIENT_X_FOR_RIGHT);
		temporary.y = float(_position.y + PROJECTILE_COEFFICIENT_Y_FOR_RIGHT);
		break;
	}
	return temporary;
}

Projectile::Projectile(Direction _direction, GameObject* _gameObjectWhoShooted, Vector2f _position) :
	DynamicObject(_direction,
		VELOCITY_PROJECTILE,
		GameObjectType::PROJECTILE,
		PROJECTILE_W, PROJECTILE_H,
		GameResources::getInstance()->getTexture(GameObjectType::PROJECTILE),
		getPositionForProjectile(_direction, _position))
{
	gameObjectWhoShooted = _gameObjectWhoShooted;
	damage = PROJECTILE_DAMAGE;
}

void Projectile::message(Message* _message)
{
	if (_message->messageType == MessageType::EMPTY)
	{
		if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and
			gameObjectWhoShooted->getGameObjectType() == GameObjectType::ENEMY and
			_message->gameObject != gameObjectWhoShooted)
		{
			if (checkCollisionAABBWithGameObject(_message->gameObject) and
				_message->gameObject != gameObjectWhoShooted)
				destroy();
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and
			gameObjectWhoShooted->getGameObjectType() == GameObjectType::PLAYER)
		{
			if (checkCollisionAABBWithGameObject(_message->gameObject))
			{
				destroy();
				dealDamage(_message->gameObject,
					damage);
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::PLAYER and
			gameObjectWhoShooted->getGameObjectType() == GameObjectType::ENEMY)
		{
			if (checkCollisionAABBWithGameObject(_message->gameObject))
			{
				destroy();
				dealDamage(_message->gameObject,
					damage);
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::PROJECTILE and
			_message->gameObject != this)
		{
			if (checkCollisionAABBWithGameObject(_message->gameObject))
				destroy();
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL or
			_message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL or
			_message->gameObject->getGameObjectType() == GameObjectType::HEADQUARTERS)
		{
			if (checkCollisionAABBWithGameObject(_message->gameObject))
			{
				if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL)
				{
					dealDamage(_message->gameObject,
						NULL);
					destroy();
				}
				else if (_message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL)
					destroy();
				else if (_message->gameObject->getGameObjectType() == GameObjectType::HEADQUARTERS)
				{
					dealDamage(_message->gameObject,
						NULL);
					destroy();
				}
			}
		}
	}
}

void Projectile::update(float _time)
{
	switch (getDirection())
	{
	case Direction::UP:
		dy = -getVelocity() * _time;
		break;
	case Direction::LEFT:
		dx = -getVelocity() * _time;
		break;
	case Direction::DOWN:
		dy = getVelocity() * _time;
		break;
	case Direction::RIGHT:
		dx = getVelocity() * _time;
		break;
	}
	position.x += dx;
	position.y += dy;
	if (position.x + getW() >= MAP_RIGHT_X)
		destroy();
	else if (position.y + getH() >= MAP_DOWN_Y)
		destroy();
	else if (position.x < MAP_LEFT_X)
		destroy();
	else if (position.y < MAP_UP_Y)
		destroy();
	empty();
	setPositionInSprite(position);
}