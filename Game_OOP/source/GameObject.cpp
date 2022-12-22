#include "..\include\GameObject.h"

#include "..\include\Game.h"

bool GameObject::checkCollisionWithGameObject(GameObject* _gameObject)
{
	return (position.y + h) > _gameObject->getY() and
		position.y < (_gameObject->getY() + _gameObject->getH()) and
		(position.x + w) > _gameObject->getX() and
		position.x < (_gameObject->getX() + _gameObject->getW());
}

void GameObject::dealDamage(GameObject* _gameObject, int _damage)
{
	sendMessageInGame(new Message(MessageType::DEALDAMAGE, this, _gameObject, _damage));
}

void GameObject::destroy()
{
	if (!destroyed)
	{
		sendMessageInGame(new Message(MessageType::DESTROY, this));
		destroyed = true;
	}
}

void GameObject::move(Vector2f _position)
{
	sendMessageInGame(new Message(MessageType::MOVE, this, _position));
}

void GameObject::setDirection()
{
	switch (direction)
	{
	case Direction::UP:
		sprite.setTextureRect(IntRect(w * FRAME_UP, 0, w, h));
		break;
	case Direction::DOWN:
		sprite.setTextureRect(IntRect(w * FRAME_DOWN, 0, w, h));
		break;
	case Direction::LEFT:
		sprite.setTextureRect(IntRect(w * FRAME_LEFT, 0, w, h));
		break;
	case Direction::RIGHT:
		sprite.setTextureRect(IntRect(w * FRAME_RIGHT, 0, w, h));
		break;
	}
}

void GameObject::setPosition(Vector2f _position)
{
	sprite.setPosition(_position);
}

Game* GameObject::game = nullptr;

GameObject::GameObject(Direction _direction, GameObjectType _gameObjectType, int _w, int _h, const char* _filename, Vector2f _position)
{
	destroyed = false;
	direction = _direction;
	gameObjectType = _gameObjectType;
	w = _w;
	h = _h;
	texture.loadFromFile(_filename);
	sprite.setTexture(texture);
	position = _position;

	game = Game::getInstance();

	setDirection();
	setPosition(_position);
}

GameObject::Direction GameObject::getDirection()
{
	return direction;
}

float GameObject::getX()
{
	return position.x;
}

float GameObject::getY()
{
	return position.y;
}

GameObject::GameObjectType GameObject::getGameObjectType()
{
	return gameObjectType;
}

int GameObject::getW()
{
	return w;
}

int GameObject::getH()
{
	return h;
}

Sprite GameObject::getSprite()
{
	return sprite;
}

Vector2f GameObject::getPosition()
{
	return position;
}

void GameObject::sendMessageInGame(Message* _message)
{
	game->receiveMessage(_message);
}