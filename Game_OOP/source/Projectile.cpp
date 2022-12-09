#include "..\include\Projectile.h"

Projectile::Projectile(Vector2f _position, Direction _direction, GameObjectType _gameObjectTypeWhoShooted, GameObject* _gameObjectWhoShooted)
{
	w = PROJECTILE_W;
	h = PROJECTILE_H;

	switch (_direction)
	{
	case Direction::UP:
		//position.x = _position.x + w + w / 2;
		//position.y = _position.y - h;
		//position.x = _position.x + (_w / (_w / w)) + (_w / (_w / w) / 2);
		//position.y = _position.y - (_h / (_h / h));
		position.x = _position.x + PROJECTILE_COEFFICIENT_X_FOR_UP;
		position.y = _position.y + PROJECTILE_COEFFICIENT_Y_FOR_UP;
		break;
	case Direction::DOWN:
		//position.x = _position.x + w + w / 2;
		//position.y = _position.y + h * 4;
		//position.x = _position.x + (_w / (_w / w)) + (_w / (_w / w) / 2);
		//position.y = _position.y + _h;
		position.x = _position.x + PROJECTILE_COEFFICIENT_X_FOR_DOWN;
		position.y = _position.y + PROJECTILE_COEFFICIENT_Y_FOR_DOWN;
		break;
	case Direction::LEFT:
		//position.x = _position.x - w;
		//position.y = _position.y + h + h / 2;
		//position.x = _position.x - (_w / (_w / w));
		//position.y = _position.y + (_h / (_h / h)) + (_h / (_h / h) / 2);
		position.x = _position.x + PROJECTILE_COEFFICIENT_X_FOR_LEFT;
		position.y = _position.y + PROJECTILE_COEFFICIENT_Y_FOR_LEFT;
		break;
	case Direction::RIGHT:
		//position.x = _position.x + w * 4;
		//position.y = _position.y + h + h / 2;
		//position.x = _position.x + _w;
		//position.y = _position.y + (_h / (_h / h)) + (_h / (_h / h) / 2);
		position.x = _position.x + PROJECTILE_COEFFICIENT_X_FOR_RIGHT;
		position.y = _position.y + PROJECTILE_COEFFICIENT_Y_FOR_RIGHT;
		break;
	}

	texture.loadFromFile(FILENAME_PNG_PROJECTILE);
	sprite.setTexture(texture);
	velocity = VELOCITY_PROJECTILE;
	direction = _direction;
	gameObjectType = GameObjectType::PROJECTILE;
	gameObjectTypeWhoShooted = _gameObjectTypeWhoShooted;
	gameObjectWhoShooted = _gameObjectWhoShooted;
	damage = PROJECTILE_DAMAGE;

	setPosition(position);
	setDirection();
}

void Projectile::update(float _time)
{
	switch (direction)
	{
	case Direction::UP:
		dy = -velocity * _time;
		break;
	case Direction::LEFT:
		dx = -velocity * _time;
		break;
	case Direction::DOWN:
		dy = velocity * _time;
		break;
	case Direction::RIGHT:
		dx = velocity * _time;
		break;
	}

	position.x += dx;
	position.y += dy;

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
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			sendMessageInGame(new Message(MessageType::DESTROY, this));
			sendMessageInGame(new Message(MessageType::DEALDAMAGE, this, _message->gameObject, damage));
			if (MESSAGES_DEBUG_IN_PROJECTILE)
				cout << "Enemy hit the player" << endl;
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and gameObjectTypeWhoShooted == GameObjectType::PLAYER)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			sendMessageInGame(new Message(MessageType::DESTROY, this));
			sendMessageInGame(new Message(MessageType::DEALDAMAGE, this, _message->gameObject, damage));
			if (MESSAGES_DEBUG_IN_PROJECTILE)
				cout << "Player hit the enemy" << endl;
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::PROJECTILE and _message->gameObject != this)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			sendMessageInGame(new Message(MessageType::DESTROY, this));
			if (MESSAGES_DEBUG_IN_PROJECTILE)
				cout << "Projectile hit the projectile" << endl;
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::ENEMY and gameObjectTypeWhoShooted == GameObjectType::ENEMY)
	{
		if (checkCollisionWithGameObject(_message->gameObject) and _message->gameObject != gameObjectWhoShooted)
		{
			sendMessageInGame(new Message(MessageType::DESTROY, this));
			if (MESSAGES_DEBUG_IN_PROJECTILE)
				cout << "Enemy hit the enemy" << endl;
		}
	}
	else if (_message->gameObject->getGameObjectType() == GameObjectType::BRICKWALL)
	{
		if (checkCollisionWithGameObject(_message->gameObject))
		{
			sendMessageInGame(new Message(MessageType::DESTROY, this));
			sendMessageInGame(new Message(MessageType::DEALDAMAGE, this, _message->gameObject, NULL));
			if (MESSAGES_DEBUG_IN_PROJECTILE)
				cout << "Game object hit the brick wall" << endl;
		}
	}
}

GameObject::GameObjectType Projectile::getGameObjectTypeWhoShooted()
{
	return gameObjectTypeWhoShooted;
}
