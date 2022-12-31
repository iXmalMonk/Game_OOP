#include "..\..\include\dynamicObjects\Enemy.h"
#include "..\..\include\utilts\GameResources.h"

void Enemy::move(float _time)
{
	dx = 0;
	dy = 0;
	if (getDirection() == Direction::UP)
	{
		if (position.y <= MAP_UP_Y)
		{
			dx = getVelocity() * _time;
			position.y = MAP_UP_Y;
			setDirection(Direction::RIGHT);
		}
		else
			dy = -getVelocity() * _time;
	}
	else if (getDirection() == Direction::LEFT)
	{
		if (position.x <= MAP_LEFT_X)
		{
			dy = -getVelocity() * _time;
			position.x = MAP_LEFT_X;
			setDirection(Direction::UP);
		}
		else
			dx = -getVelocity() * _time;
	}
	else if (getDirection() == Direction::DOWN)
	{
		if (position.y + getH() >= MAP_DOWN_Y)
		{
			dx = -getVelocity() * _time;
			position.y = float(MAP_DOWN_Y - getH());
			setDirection(Direction::LEFT);
		}
		else
			dy = getVelocity() * _time;
	}
	else if (getDirection() == Direction::RIGHT)
	{
		if (position.x + getW() >= MAP_RIGHT_X)
		{
			dy = getVelocity() * _time;
			position.x = float(MAP_RIGHT_X - getW());
			setDirection(Direction::DOWN);
		}
		else
			dx = getVelocity() * _time;
	}

	position.x += dx;
	position.y += dy;
	setPositionInSprite(position);
}

void Enemy::randomDirection(float _time)
{
	cooldownTimeForRandomDirection += _time;
	if (cooldownTimeForRandomDirection >= cooldownMaxTimeForRandomDirection)
	{
		cooldownTimeForRandomDirection = 0;
		auto random = rand() % 4;
		switch (random)
		{
		case 0:
			setDirection(Direction::UP);
			break;
		case 1:
			setDirection(Direction::DOWN);
			break;
		case 2:
			setDirection(Direction::LEFT);
			break;
		case 3:
			setDirection(Direction::RIGHT);
			break;
		}
	}
}

Enemy::Enemy(Vector2f _position) :
	Tank(Direction::DOWN,
		VELOCITY_ENEMY,
		GameObjectType::ENEMY,
		GameResources::getInstance()->getTexture(GameObjectType::ENEMY),
		_position)
{
	cooldownMaxTimeForRandomDirection = 1;
	cooldownTimeForRandomDirection = 0;
}

void Enemy::update(float _time)
{
	if (readyToShoot(_time) and 
		rand() % 10 == 0)
		shoot();
	randomDirection(_time);
	move(_time);
	empty();
}