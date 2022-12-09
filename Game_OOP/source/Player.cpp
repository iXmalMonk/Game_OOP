#include "..\include\Player.h"

Player::Player()
{
	w = 64;
	h = 64;
	position.x = WINDOW_W / 2;
	position.y = WINDOW_H / 2;
	texture.loadFromFile("png/playerTank.png");
	sprite.setTexture(texture);
	velocity = 0.015;
	direction = Direction::UP;
	gameObjectType = GameObjectType::PLAYER;

	setPosition(position);
	setDirection();
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

	sendMessageInGame(new Message(MessageType::MOVE, this, getPosition()));
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
	}
}
