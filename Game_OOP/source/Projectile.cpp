#include "..\include\Projectile.h"

Projectile::Projectile(Vector2f _position, Direction _direction)
{
	w = 16;
	h = 16;
	if (_direction == Direction::UP)
	{
		position.x = _position.x + w + w / 2;
		position.y = _position.y - h;
	}
	else if (_direction == Direction::DOWN)
	{
		position.x = _position.x + w + w / 2;
		position.y = _position.y + h * 4;
	}
	else if (_direction == Direction::LEFT)
	{
		position.x = _position.x - w;
		position.y = _position.y + h + h / 2;
	}
	else if (_direction == Direction::RIGHT)
	{
		position.x = _position.x + w * 4;
		position.y = _position.y + h + h / 2;
	}
	texture.loadFromFile("png/projectile.png");
	sprite.setTexture(texture);
	velocity = 0.015;
	direction = _direction;

	setPosition(position);
	setDirection();
}

void Projectile::update(float _time)
{
	if (direction == Direction::UP)
		position.y -= velocity * _time;
	if (direction == Direction::LEFT)
		position.x -= velocity * _time;
	if (direction == Direction::DOWN)
		position.y += velocity * _time;
	if (direction == Direction::RIGHT)
		position.x += velocity * _time;

	if (position.x + w >= WINDOW_W)
		sendMessage(new Message(MessageType::DESTROY, this));
	else if (position.y + h >= WINDOW_H)
		sendMessage(new Message(MessageType::DESTROY, this));
	else if (position.x < 0)
		sendMessage(new Message(MessageType::DESTROY, this));
	else if (position.y < 0)
		sendMessage(new Message(MessageType::DESTROY, this));

	setPosition(position);
}
