#include "..\include\Projectile.h"

void Projectile::dealDamage(GameObject* _gameObject, int _damage)
{
	sendMessageInGame(new Message(MessageType::DEALDAMAGE, this, _gameObject, _damage));
}

Vector2f Projectile::getPositionForProjectile(Vector2f _position, Direction _direction)
{
	Vector2f temporary;

	switch (_direction)
	{
	case GameObject::Direction::UP:
		temporary.x = _position.x + PROJECTILE_COEFFICIENT_X_FOR_UP;
		temporary.y = _position.y + PROJECTILE_COEFFICIENT_Y_FOR_UP;
		break;
	case GameObject::Direction::DOWN:
		temporary.x = _position.x + PROJECTILE_COEFFICIENT_X_FOR_DOWN;
		temporary.y = _position.y + PROJECTILE_COEFFICIENT_Y_FOR_DOWN;
		break;
	case GameObject::Direction::LEFT:
		temporary.x = _position.x + PROJECTILE_COEFFICIENT_X_FOR_LEFT;
		temporary.y = _position.y + PROJECTILE_COEFFICIENT_Y_FOR_LEFT;
		break;
	case GameObject::Direction::RIGHT:
		temporary.x = _position.x + PROJECTILE_COEFFICIENT_X_FOR_RIGHT;
		temporary.y = _position.y + PROJECTILE_COEFFICIENT_Y_FOR_RIGHT;
		break;
	}

	return temporary;
}

Projectile::Projectile(Vector2f _position, Direction _direction, GameObject* _gameObjectWhoShooted) : DynamicObject(VELOCITY_PROJECTILE, _direction, GameObjectType::PROJECTILE, PROJECTILE_W, PROJECTILE_H, FILENAME_PNG_PROJECTILE, getPositionForProjectile(_position, _direction))
{
	gameObjectWhoShooted = _gameObjectWhoShooted;
	damage = PROJECTILE_DAMAGE;
}

void Projectile::receiveMessage(Message* _message)
{
	if (_message->messageType == GameObject::MessageType::EMPTY)
	{
		if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and gameObjectWhoShooted->getGameObjectType() == GameObjectType::ENEMY)
		{
			if (checkCollisionWithGameObject(_message->gameObject) and _message->gameObject != gameObjectWhoShooted)
			{
				destroy();
				if (MESSAGES_DEBUG_IN_PROJECTILE)
					cout << "Enemy hit the enemy" << endl;
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and gameObjectWhoShooted->getGameObjectType() == GameObjectType::PLAYER)
		{
			if (checkCollisionWithGameObject(_message->gameObject))
			{
				destroy();
				dealDamage(_message->gameObject, damage);
				if (MESSAGES_DEBUG_IN_PROJECTILE)
					cout << "Player hit the enemy" << endl;
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::PLAYER and gameObjectWhoShooted->getGameObjectType() == GameObjectType::ENEMY)
		{
			if (checkCollisionWithGameObject(_message->gameObject))
			{
				destroy();
				dealDamage(_message->gameObject, damage);
				if (MESSAGES_DEBUG_IN_PROJECTILE)
					cout << "Enemy hit the player" << endl;
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::PROJECTILE and _message->gameObject != this)
		{
			if (checkCollisionWithGameObject(_message->gameObject))
			{
				destroy();
				if (MESSAGES_DEBUG_IN_PROJECTILE)
					cout << "Projectile hit the projectile" << endl;
			}
		}
		else if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL or _message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL)
		{
			if (checkCollisionWithGameObject(_message->gameObject))
			{
				if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::BRICKWALL)
				{
					dealDamage(_message->gameObject, NULL);
					destroy();
					if (MESSAGES_DEBUG_IN_PROJECTILE)
						cout << "Game object hit the brick wall" << endl;
				}
				else if (_message->gameObject->getGameObjectType() == GameObject::GameObjectType::CONCRETEWALL)
				{
					destroy();
					if (MESSAGES_DEBUG_IN_PROJECTILE)
						cout << "Game object hit the concrete wall" << endl;
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

	if (position.x + getW() >= WINDOW_W)
		destroy();
	else if (position.y + getH() >= WINDOW_H)
		destroy();
	else if (position.x < 0)
		destroy();
	else if (position.y < 0)
		destroy();

	empty();
	setPosition(position);
}