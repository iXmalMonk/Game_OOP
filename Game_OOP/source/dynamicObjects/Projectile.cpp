#include "..\..\include\dynamicObjects\Projectile.h"
#include "..\..\include\utilts\Game.h"
#include "..\..\include\utilts\GameResources.h"

Vector2f Projectile::getPositionForProjectile(Direction _direction, Vector2f _position)
{
	Vector2f temporary;
	switch (_direction)
	{
	case Direction::UP:
		temporary.x = float(_position.x + TANK_W / 2 - PROJECTILE_W / 2);
		temporary.y = float(_position.y - PROJECTILE_H);
		break;
	case Direction::DOWN:
		temporary.x = float(_position.x + TANK_W / 2 - PROJECTILE_W / 2);
		temporary.y = float(_position.y + TANK_H);
		break;
	case Direction::LEFT:
		temporary.x = float(_position.x - PROJECTILE_W);
		temporary.y = float(_position.y + TANK_H / 2 - PROJECTILE_H / 2);
		break;
	case Direction::RIGHT:
		temporary.x = float(_position.x + TANK_W);
		temporary.y = float(_position.y + TANK_H / 2 - PROJECTILE_H / 2);
		break;
	}
	return temporary;
}

void Projectile::dealDamageMessage(GameObject* _gameObject, int _damage)
{
	Game::getInstance()->message(new Message(this,
		_gameObject,
		_damage,
		MessageType::DEALDAMAGE));
	destroyMessage();
}

void Projectile::move(float _time)
{
	switch (getDirection())
	{
	case Direction::UP:
		dy = -velocity * _time;
		break;
	case Direction::LEFT:
		dx = -velocity * _time;
		break;
	case Direction::DOWN:
		dy = velocity * _time;
		break;
	case Direction::RIGHT:
		dx = velocity * _time;
		break;
	}
	position.x += dx;
	position.y += dy;
	if (position.x + getW() >= MAP_RIGHT)
		destroyMessage();
	else if (position.y + getH() >= MAP_DOWN)
		destroyMessage();
	else if (position.x < MAP_LEFT)
		destroyMessage();
	else if (position.y < MAP_UP)
		destroyMessage();
	setPositionInSprite(position);
}

Projectile::Projectile(Direction _direction, GameObject* _gameObjectWhoShooted, GameObjectType _gameObjectTypeWhoShooted, Vector2f _position) :
	DynamicObject(_direction,
		PROJECTILE_VELOCITY,
		GameObjectType::PROJECTILE,
		PROJECTILE_W, PROJECTILE_H,
		GameResources::getInstance()->getTexture(GameObjectType::PROJECTILE),
		getPositionForProjectile(_direction, _position))
{
	gameObjectWhoShooted = _gameObjectWhoShooted;
	gameObjectTypeWhoShooted = _gameObjectTypeWhoShooted;
	damage = PROJECTILE_DAMAGE;
}

void Projectile::message(Message* _message)
{
	if (_message->messageType == MessageType::EMPTY and
		isCollisionAABBWithGameObject(_message->gameObject))
	{
		if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and
			gameObjectTypeWhoShooted == GameObjectType::ENEMY and
			_message->gameObject != gameObjectWhoShooted)
			destroyMessage();
		else if ((_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and
			gameObjectTypeWhoShooted == GameObjectType::PLAYER) or
			(_message->gameObject->getGameObjectType() == GameObjectType::PLAYER and
			gameObjectTypeWhoShooted == GameObjectType::ENEMY))
			dealDamageMessage(_message->gameObject,
				damage);
		else if (_message->gameObject->getGameObjectType() == GameObjectType::PROJECTILE and
			_message->gameObject != this)
			destroyMessage();
		else if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL or
			_message->gameObject->getGameObjectType() == GameObjectType::HEADQUARTERS)
			dealDamageMessage(_message->gameObject,
				NULL);
		else if (_message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL)
			destroyMessage();
	}
}

void Projectile::update(float _time)
{
	move(_time);
	emptyMessage();
}