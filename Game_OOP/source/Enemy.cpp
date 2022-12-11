#include "..\include\Enemy.h"

Enemy::Enemy(Vector2f _position)
{
	position.x = _position.x;
	position.y = _position.y;
	texture.loadFromFile(FILENAME_PNG_ENEMY);
	sprite.setTexture(texture);
	velocity = VELOCITY_ENEMY;
	direction = Direction::DOWN;
	gameObjectType = GameObjectType::ENEMY;

	setPosition(position);
	setDirection();
}

void Enemy::update(float _time)
{
	if (readyToShoot(_time))
		shoot();

	dx = 0;
	dy = 0;

	if (direction == Direction::UP)
	{
		if (position.y <= 0)
		{
			dx = velocity * _time;
			position.y = 0;
			direction = Direction::RIGHT;
		}
		else
			dy = -velocity * _time;
	}
	else if (direction == Direction::LEFT)
	{
		if (position.x <= 0)
		{
			dy = -velocity * _time;
			position.x = 0;
			direction = Direction::UP;
		}
		else
			dx = -velocity * _time;
	}
	else if (direction == Direction::DOWN)
	{
		if (position.y + h >= WINDOW_H)
		{
			dx = -velocity * _time;
			position.y = WINDOW_H - h;
			direction = Direction::LEFT;
		}
		else
			dy = velocity * _time;
	}
	else if (direction == Direction::RIGHT)
	{
		if (position.x + w >= WINDOW_W)
		{
			dy = velocity * _time;
			position.x = WINDOW_W - w;
			direction = Direction::DOWN;
		}
		else
			dx = velocity * _time;
	}

	position.x += dx;
	position.y += dy;

	move(getPosition());
	setPosition(position);
	setDirection();
}

void Enemy::receiveMessage(GameObject::Message* _message)
{
	if (_message->dealDamage.gameObject == this)
	{
		setHealthPoints(getHealthPoints() - _message->dealDamage.damage);
		if (MESSAGES_DEBUG_IN_ENEMY)
			cout << "Enemy HP: " << getHealthPoints() << endl;
		alive();
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::PLAYER)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::WATER)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
		}
	}
}