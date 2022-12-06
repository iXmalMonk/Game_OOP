#include "..\include\Projectile.h"

Projectile::Projectile(Vector2f _position, Direction _direction, int _w, int _h)
{
	w = 16;
	h = 16;

	switch (_direction)
	{
	case Direction::UP:
		//position.x = _position.x + w + w / 2;
		//position.y = _position.y - h;
		position.x = _position.x + (_w / (_w / w)) + (_w / (_w / w) / 2);
		position.y = _position.y - (_h / (_h / h));
		break;
	case Direction::DOWN:
		//position.x = _position.x + w + w / 2;
		//position.y = _position.y + h * 4;
		position.x = _position.x + (_w / (_w / w)) + (_w / (_w / w) / 2);
		position.y = _position.y + _h;
		break;
	case Direction::LEFT:
		//position.x = _position.x - w;
		//position.y = _position.y + h + h / 2;
		position.x = _position.x - (_w / (_w / w));
		position.y = _position.y + (_h / (_h / h)) + (_h / (_h / h) / 2);
		break;
	case Direction::RIGHT:
		//position.x = _position.x + w * 4;
		//position.y = _position.y + h + h / 2;
		position.x = _position.x + _w;
		position.y = _position.y + (_h / (_h / h)) + (_h / (_h / h) / 2);
		break;
	}

	texture.loadFromFile("png/projectile.png");
	sprite.setTexture(texture);
	velocity = 0.03;
	direction = _direction;

	setPosition(position);
	setDirection();
}

void Projectile::update(float _time)
{
	switch (direction)
	{
	case Direction::UP:
		position.y -= velocity * _time;
		break;
	case Direction::DOWN:
		position.y += velocity * _time;
		break;
	case Direction::LEFT:
		position.x -= velocity * _time;
		break;
	case Direction::RIGHT:
		position.x += velocity * _time;
		break;
	}

	if (position.x + w >= WINDOW_W)
		sendMessage(MessageType::DESTROY);
	else if (position.y + h >= WINDOW_H)
		sendMessage(MessageType::DESTROY);
	else if (position.x < 0)
		sendMessage(MessageType::DESTROY);
	else if (position.y < 0)
		sendMessage(MessageType::DESTROY);

	setPosition(position);
}
