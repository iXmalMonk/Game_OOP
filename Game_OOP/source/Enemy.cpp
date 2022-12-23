#include "..\include\Enemy.h"

Enemy::Enemy(Vector2f _position) : Tank(VELOCITY_ENEMY, Direction::DOWN, GameObjectType::ENEMY, FILENAME_PNG_ENEMY, _position) {}

void Enemy::receiveMessage(GameObject::Message* _message)
{
	if (_message->messageType == GameObject::MessageType::DEALDAMAGE and _message->dealDamage.gameObject == this)
	{
		setHealthPoints(getHealthPoints() - _message->dealDamage.damage);
		if (MESSAGES_DEBUG_IN_ENEMY)
			cout << "Enemy HP: " << getHealthPoints() << endl;
		alive();
	}
	else if (_message->messageType == GameObject::MessageType::EMPTY and _message->gameObject->getGameObjectType() != GameObjectType::FOREST and _message->gameObject != this)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
		}
	}
}

void Enemy::update(float _time)
{
	if (readyToShoot(_time))
		shoot();

	dx = 0;
	dy = 0;

	if (getDirection() == Direction::UP)
	{
		if (position.y <= 0)
		{
			dx = getVelocity() * _time;
			position.y = 0;
			setDirection(Direction::RIGHT);
		}
		else
			dy = -getVelocity() * _time;
	}
	else if (getDirection() == Direction::LEFT)
	{
		if (position.x <= 0)
		{
			dy = -getVelocity() * _time;
			position.x = 0;
			setDirection(Direction::UP);
		}
		else
			dx = -getVelocity() * _time;
	}
	else if (getDirection() == Direction::DOWN)
	{
		if (position.y + getH() >= WINDOW_H)
		{
			dx = -getVelocity() * _time;
			position.y = WINDOW_H - getH();
			setDirection(Direction::LEFT);
		}
		else
			dy = getVelocity() * _time;
	}
	else if (getDirection() == Direction::RIGHT)
	{
		if (position.x + getW() >= WINDOW_W)
		{
			dy = getVelocity() * _time;
			position.x = WINDOW_W - getW();
			setDirection(Direction::DOWN);
		}
		else
			dx = getVelocity() * _time;
	}

	position.x += dx;
	position.y += dy;

	empty();
	setPosition(position);
}