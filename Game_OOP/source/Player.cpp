#include "..\include\Player.h"

Player::Player(Vector2f _position) : Tank(FILENAME_PNG_PLAYER,Direction::UP, VELOCITY_PLAYER, GameObjectType::PLAYER, _position) {}

void Player::update(float _time)
{
	if (readyToShoot(_time) and Keyboard::isKeyPressed(Keyboard::Space))
		shoot();
	dx = 0;
	dy = 0;
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		setDirection(Direction::UP);
		dy = -getVelocity() * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		setDirection(Direction::LEFT);
		dx = -getVelocity() * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		setDirection(Direction::DOWN);
		dy = getVelocity() * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		setDirection(Direction::RIGHT);
		dx = getVelocity() * _time;
	}
	position.x += dx;
	position.y += dy;
	if (position.y < 0)
		position.y = 0;
	if (position.x < 0)
		position.x = 0;
	if (position.y + getH() > WINDOW_H)
		position.y = WINDOW_H - getH();
	if (position.x + getW() > WINDOW_W)
		position.x = WINDOW_W - getW();
	empty();
	setPositionInSprite(position);
}