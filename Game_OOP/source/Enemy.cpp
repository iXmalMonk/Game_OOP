#include "..\include\Enemy.h"

Enemy::Enemy()
{
	w = 64;
	h = 64;
	position.x = 0;
	position.y = 0;
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

	if (direction == Direction::UP)
	{
		position.y -= velocity * _time;

		if (position.y <= 0)
		{
			position.y = 0;
			direction = Direction::RIGHT;
		}
	}
	else if (direction == Direction::LEFT)
	{
		position.x -= velocity * _time;

		if (position.x <= 0)
		{
			position.x = 0;
			direction = Direction::UP;
		}
	}
	else if (direction == Direction::DOWN)
	{
		position.y += velocity * _time;

		if (position.y + h >= WINDOW_H)
		{
			position.y = WINDOW_H - h;
			direction = Direction::LEFT;
		}
	}
	else if (direction == Direction::RIGHT)
	{
		position.x += velocity * _time;

		if (position.x + w >= WINDOW_W)
		{
			position.x = WINDOW_W - w;
			direction = Direction::DOWN;
		}
	}

	sendMessageInGame(new Message(MessageType::MOVE, this, getPosition()));
	setPosition(position);
	setDirection();
}

void Enemy::receiveMessage(GameObject::Message* _message)
{
	if (_message->gameObject->getGameObjectType() == GameObjectType::PLAYER)
		;//cout << "Enemy - Player: X = " << _message->gameObject->getX() << " Y = " << _message->gameObject->getY() << endl;
}
