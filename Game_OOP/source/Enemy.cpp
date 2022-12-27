#include "..\include\Enemy.h"
#include "..\include\Game.h"

Enemy::Enemy(Vector2f _position) : Tank(Direction::DOWN, VELOCITY_ENEMY, GameObjectType::ENEMY, Game::getInstance()->getTexture(GameObjectType::ENEMY), _position) {}

void Enemy::update(float _time)
{
	if (readyToShoot(_time))
		shoot();
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
	empty();
	setPositionInSprite(position);
}