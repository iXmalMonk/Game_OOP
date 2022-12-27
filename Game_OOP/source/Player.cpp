#include "..\include\Player.h"
#include "..\include\Game.h"

Player::Player(Vector2f _position) : Tank(Direction::UP, VELOCITY_PLAYER, GameObjectType::PLAYER, Game::getInstance()->getTexture(GameObjectType::PLAYER), _position) {}

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
	if (position.y < MAP_UP_Y)
		position.y = MAP_UP_Y;
	if (position.x < MAP_LEFT_X)
		position.x = MAP_LEFT_X;
	if (position.y + getH() > MAP_DOWN_Y)
		position.y = float(MAP_DOWN_Y - getH());
	if (position.x + getW() > MAP_RIGHT_X)
		position.x = float(MAP_RIGHT_X - getW());
	empty();
	setPositionInSprite(position);
}