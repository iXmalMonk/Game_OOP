#include "..\include\Player.h"

Player::Player(Vector2f _position) : Tank(VELOCITY_PLAYER, Direction::UP, GameObjectType::PLAYER, FILENAME_PNG_PLAYER, _position) {}

void Player::message(Message* _message)
{
	if (_message->messageType == MessageType::DEALDAMAGE and
		_message->dealDamage.gameObject == this)
	{
		setHealthPoints(getHealthPoints() - _message->dealDamage.damage);
		if (MESSAGES_DEBUG_IN_PLAYER)
			cout << "Player HP: " << getHealthPoints() << endl;
		alive();
	}
	else if (_message->messageType == MessageType::EMPTY and
		_message->gameObject->getGameObjectType() != GameObjectType::FOREST and
		_message->gameObject->getGameObjectType() != GameObjectType::PROJECTILE and
		_message->gameObject != this)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPositionInSprite(position);
		}
	}
}

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