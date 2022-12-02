#include "..\include\Player.h"

Player::Player()
{
	this->position.x = WINDOW_W / 2;
	this->position.y = WINDOW_H / 2;
	this->texture.loadFromFile("png/playerTank.png");
	this->sprite.setTexture(this->texture);
	this->w = 64;
	this->h = 64;
	this->velocity = 0.01;
	this->direction = Direction::UP;
}

void Player::update(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->direction = Direction::UP;
		this->position.y -= this->velocity * time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->direction = Direction::LEFT;
		this->position.x -= this->velocity * time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->direction = Direction::DOWN;
		this->position.y += this->velocity * time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->direction = Direction::RIGHT;
		this->position.x += this->velocity * time;
	}

	setDirection(this->direction);
	setPosition(this->position);
}
