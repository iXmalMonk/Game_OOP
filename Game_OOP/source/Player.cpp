#include "..\include\Player.h"

Player::Player()
{
	position.x = WINDOW_W / 2;
	position.y = WINDOW_H / 2;
	texture.loadFromFile(FILENAME_PNG_PLAYER);
	sprite.setTexture(texture);
	velocity = VELOCITY_PLAYER;
	direction = Direction::UP;
	gameObjectType = GameObjectType::PLAYER;

	setPosition(position);
	setDirection();
}

void Player::receiveMessage(Message* _message)
{
	if (_message->dealDamage.gameObject == this)
	{
		setHealthPoints(getHealthPoints() - _message->dealDamage.damage);
		if (MESSAGES_DEBUG_IN_PLAYER)
			cout << "Player HP: " << getHealthPoints() << endl;
		alive();
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::WATER)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::CONCRETEWALL)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			position.x -= dx;
			position.y -= dy;
			setPosition(position);
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
		direction = Direction::UP;
		dy = -velocity * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		direction = Direction::LEFT;
		dx = -velocity * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		direction = Direction::DOWN;
		dy = velocity * _time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		direction = Direction::RIGHT;
		dx = velocity * _time;
	}

	position.x += dx;
	position.y += dy;

	if (position.y < 0)
		position.y = 0;
	if (position.x < 0)
		position.x = 0;
	if (position.y + h > WINDOW_H)
		position.y = WINDOW_H - h;
	if (position.x + w > WINDOW_W)
		position.x = WINDOW_W - w;

	move(getPosition());
	setPosition(position);
	setDirection();
}