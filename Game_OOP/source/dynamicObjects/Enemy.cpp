#include "..\..\include\dynamicObjects\Enemy.h"
#include "..\..\include\utilts\GameResources.h"

void Enemy::move(float _time)
{
	dx = 0;
	dy = 0;
	randomDirection(_time);
	if (getDirection() == Direction::UP)
	{
		if (position.y <= MAP_UP)
		{
			dx = velocity * _time;
			position.y = MAP_UP;
			setDirection(Direction::RIGHT);
		}
		else
			dy = -velocity * _time;
	}
	else if (getDirection() == Direction::LEFT)
	{
		if (position.x <= MAP_LEFT)
		{
			dy = -velocity * _time;
			position.x = MAP_LEFT;
			setDirection(Direction::UP);
		}
		else
			dx = -velocity * _time;
	}
	else if (getDirection() == Direction::DOWN)
	{
		if (position.y + getH() >= MAP_DOWN)
		{
			dx = -velocity * _time;
			position.y = float(MAP_DOWN - getH());
			setDirection(Direction::LEFT);
		}
		else
			dy = velocity * _time;
	}
	else if (getDirection() == Direction::RIGHT)
	{
		if (position.x + getW() >= MAP_RIGHT)
		{
			dy = velocity * _time;
			position.x = float(MAP_RIGHT - getW());
			setDirection(Direction::DOWN);
		}
		else
			dx = velocity * _time;
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
		ENEMY_VELOCITY,
		GameObjectType::ENEMY,
		GameResources::getInstance()->getTexture(GameObjectType::ENEMY),
		_position)
{
	cooldownMaxTimeForRandomDirection = ENEMY_COOLDOWN_MAX_TIME_FOR_RANDOM_DIRECTION;
	cooldownTimeForRandomDirection = 0;
}

void Enemy::update(float _time)
{
	if (isReadyToShoot(_time) and 
		rand() % ENEMY_SHOT_CHANCE == 0)
		shoot();
	move(_time);
	emptyMessage();
}