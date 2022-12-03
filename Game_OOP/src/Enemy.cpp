#include "..\include\Enemy.h"

Enemy::Enemy()
{
	this->position.x = 0;
	this->position.y = 0;
	this->texture.loadFromFile("png/enemyTank.png");
	this->sprite.setTexture(this->texture);
	this->w = 64;
	this->h = 64;
	this->velocity = 0.01;
	this->direction = Direction::DOWN;
	this->healthPoints = 100;
}

void Enemy::update(float time)
{
	if (this->direction == Direction::UP)
	{
		this->position.y -= this->velocity * time;

		if (this->position.y < 0)
		{
			this->position.y = 0;
			this->direction = Direction::RIGHT;
		}
	}
	else if (this->direction == Direction::LEFT)
	{
		this->position.x -= this->velocity * time;

		if (this->position.x < 0)
		{
			this->position.x = 0;
			this->direction = Direction::UP;
		}
	}
	else if (this->direction == Direction::DOWN)
	{
		this->position.y += this->velocity * time;

		if (this->position.y + this->h > WINDOW_H)
		{
			this->position.y = WINDOW_H - this->h;
			this->direction = Direction::LEFT;
		}
	}
	else if (this->direction == Direction::RIGHT)
	{
		this->position.x += this->velocity * time;

		if (this->position.x + this->w > WINDOW_W)
		{
			this->position.x = WINDOW_W - this->w;
			this->direction = Direction::DOWN;
		}
	}

	setDirection(this->direction);
	setPosition(this->position);
}
