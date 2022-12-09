#include "..\include\Enemy.h"

Enemy::Enemy(Vector2f _position)
{
	w = 64;
	h = 64;
	position.x = _position.x;
	position.y = _position.y;
	texture.loadFromFile("png/enemyTank.png");
	sprite.setTexture(texture);
	velocity = 0.01;
	direction = Direction::DOWN;
	gameObjectType = GameObjectType::ENEMY;

	setPosition(position);
	setDirection();
}

void Enemy::update(float _time)
{
	if (readyToShoot(_time))
		shoot();

	dx = 0;
	dy = 0;

	if (direction == Direction::UP)
	{
		if (position.y <= 0)
		{
			dx = velocity * _time;
			position.y = 0;
			direction = Direction::RIGHT;
		}
		else
			dy = -velocity * _time;
	}
	else if (direction == Direction::LEFT)
	{
		if (position.x <= 0)
		{
			dy = -velocity * _time;
			position.x = 0;
			direction = Direction::UP;
		}
		else
			dx = -velocity * _time;
	}
	else if (direction == Direction::DOWN)
	{
		if (position.y + h >= WINDOW_H)
		{
			dx = -velocity * _time;
			position.y = WINDOW_H - h;
			direction = Direction::LEFT;
		}
		else
			dy = velocity * _time;
	}
	else if (direction == Direction::RIGHT)
	{
		if (position.x + w >= WINDOW_W)
		{
			dy = velocity * _time;
			position.x = WINDOW_W - w;
			direction = Direction::DOWN;
		}
		else
			dx = velocity * _time;
	}

	position.x += dx;
	position.y += dy;

	sendMessageInGame(new Message(MessageType::MOVE, this, getPosition()));
	setPosition(position);
	setDirection();
}

void Enemy::receiveMessage(GameObject::Message* _message)
{
	if (_message->dealDamage.gameObject == this)
	{
		setHealthPoints(getHealthPoints() - _message->dealDamage.damage);
		if (MESSAGES_DEBUG_IN_ENEMY)
			cout << "Enemy HP: " << getHealthPoints() << endl;
	}
}
