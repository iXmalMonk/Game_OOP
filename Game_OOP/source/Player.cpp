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

	sendMessageInGame(new Message(MessageType::MOVE, this, getPosition()));
	setPosition(position);
	setDirection();
}

void Player::receiveMessage(Message* _message)
{
	if (_message->gameObject->getGameObjectType() == GameObjectType::PROJECTILE)
		cout << "Player - Projectile: X = " << _message->gameObject->getX() << " Y = " << _message->gameObject->getY() << endl;
	else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY)
		cout << "Player - Enemy: X = " << _message->gameObject->getX() << " Y = " << _message->gameObject->getY() << endl;
}
