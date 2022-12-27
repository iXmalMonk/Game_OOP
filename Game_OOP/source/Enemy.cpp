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
			position.y = float(WINDOW_H - getH());
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
			position.x = float(WINDOW_W - getW());
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