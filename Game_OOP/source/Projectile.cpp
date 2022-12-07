#include "..\include\Projectile.h"

bool Projectile::checkCollisionProjectileWithGameObject(GameObject* _gameObject)
{
	return (position.y + h) >= _gameObject->getY() and
		position.y <= (_gameObject->getY() + _gameObject->getH()) and
		(position.x + w) >= _gameObject->getX() and
		position.x <= (_gameObject->getX() + _gameObject->getW());
}

Projectile::Projectile(Vector2f _position, Direction _direction, int _w, int _h, GameObjectType _gameObjectTypeWhoShooted)
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
	gameObjectType = GameObjectType::PROJECTILE;
	gameObjectTypeWhoShooted = _gameObjectTypeWhoShooted;

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
		sendMessageInGame(new Message(MessageType::DESTROY, this));
	else if (position.y + h >= WINDOW_H)
		sendMessageInGame(new Message(MessageType::DESTROY, this));
	else if (position.x < 0)
		sendMessageInGame(new Message(MessageType::DESTROY, this));
	else if (position.y < 0)
		sendMessageInGame(new Message(MessageType::DESTROY, this));

	sendMessageInGame(new Message(MessageType::MOVE, this, getPosition()));
	setPosition(position);
}

void Projectile::receiveMessage(Message* _message)
{
	if (_message->gameObject->getGameObjectType() == GameObjectType::PLAYER and gameObjectTypeWhoShooted == GameObjectType::ENEMY)
	{
		if (checkCollisionProjectileWithGameObject(_message->gameObject))
		{
			sendMessageInGame(new Message(MessageType::DESTROY, this));
			cout << "Enemy hit the player" << endl;
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and gameObjectTypeWhoShooted == GameObjectType::PLAYER)
	{
		if (checkCollisionProjectileWithGameObject(_message->gameObject))
		{
			sendMessageInGame(new Message(MessageType::DESTROY, this));
			cout << "Player hit the enemy" << endl;
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::PROJECTILE and _message->gameObject != this)
	{
		if (checkCollisionProjectileWithGameObject(_message->gameObject))
		{
			sendMessageInGame(new Message(MessageType::DESTROY, this));
			cout << "Projectile hit the projectile" << endl;
		}
	}
}

GameObject::GameObjectType Projectile::getGameObjectTypeWhoShooted()
{
	return gameObjectTypeWhoShooted;
}
