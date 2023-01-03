#include "..\..\include\dynamicObjects\Player.h"
#include "..\..\include\utilts\GameResources.h"

void Player::move(float _time)
{
	dx = 0;
	dy = 0;
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		setDirection(Direction::UP);
		dy = -velocity * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		setDirection(Direction::LEFT);
		dx = -velocity * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		setDirection(Direction::DOWN);
		dy = velocity * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		setDirection(Direction::RIGHT);
		dx = velocity * _time;
	}
	position.x += dx;
	position.y += dy;
	if (position.y < MAP_UP)
		position.y = MAP_UP;
	if (position.x < MAP_LEFT)
		position.x = MAP_LEFT;
	if (position.y + getH() > MAP_DOWN)
		position.y = float(MAP_DOWN - getH());
	if (position.x + getW() > MAP_RIGHT)
		position.x = float(MAP_RIGHT - getW());
	setPositionInSprite(position);
}

Player::Player(Vector2f _position) :
	Tank(Direction::UP,
		VELOCITY_PLAYER,
		GameObjectType::PLAYER,
		GameResources::getInstance()->getTexture(GameObjectType::PLAYER),
		_position) {}

void Player::update(float _time)
{
	if (isReadyToShoot(_time) and
		Keyboard::isKeyPressed(Keyboard::Space))
		shoot();
	move(_time);
	emptyMessage();
}