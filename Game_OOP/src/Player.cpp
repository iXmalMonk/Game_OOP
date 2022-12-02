#include "..\include\Player.h"

Player::Player()
{
	this->position.x = 320;
	this->position.y = 240;
	this->texture.loadFromFile("png/playerTank.png");
	this->sprite.setTexture(this->texture);
	this->velocity = 0.015;
	this->direction = Direction::UP;
}

void Player::update(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		setDirection(Direction::UP);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		setDirection(Direction::LEFT);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		setDirection(Direction::DOWN);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		setDirection(Direction::RIGHT);
	}

	setPosition(position);
}
