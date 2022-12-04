#include "..\include\Player.h"

Player::Player()
{
	w = 64;
	h = 64;
	position.x = WINDOW_W / 2;
	position.y = WINDOW_H / 2;
	texture.loadFromFile("png/playerTank.png");
	sprite.setTexture(texture);
	velocity = 0.01;
	direction = Direction::UP;

	setPosition(position);
	setDirection();
}

void Player::update(float _time)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
		shoot();

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		direction = Direction::UP;
		position.y -= velocity * _time;

		if (position.y < 0)
			position.y = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		direction = Direction::LEFT;
		position.x -= velocity * _time;

		if (position.x < 0)
			position.x = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		direction = Direction::DOWN;
		position.y += velocity * _time;

		if (position.y + h > WINDOW_H)
			position.y = WINDOW_H - h;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		direction = Direction::RIGHT;
		position.x += velocity * _time;

		if (position.x + w > WINDOW_W)
			position.x = WINDOW_W - w;
	}

	setPosition(position);
	setDirection();
}