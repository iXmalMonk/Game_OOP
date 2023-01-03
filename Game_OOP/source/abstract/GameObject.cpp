#include "..\..\include\abstract\GameObject.h"
#include "..\..\include\utilts\Game.h"

GameObject::Message::Message(GameObject* _gameObject, GameObjectType _gameObjectType, MessageType _messageType, Vector2f _position) :
	dealDamage{}
{
	create.gameObjectType = _gameObjectType;
	create.position = _position;
	gameObject = _gameObject;
	messageType = _messageType;
}

GameObject::Message::Message(GameObject* _gameObjectWho, GameObject* _gameObjectWhom, int _damage, MessageType _messageType) :
	create{}
{
	dealDamage.damage = _damage;
	dealDamage.gameObject = _gameObjectWhom;
	gameObject = _gameObjectWho;
	messageType = _messageType;
}

GameObject::Message::Message(GameObject* _gameObject, MessageType _messageType) :
	create{}
{
	gameObject = _gameObject;
	messageType = _messageType;
}

bool GameObject::isCollisionAABBWithGameObject(GameObject* _gameObject)
{
	return (position.y + h) > _gameObject->getY() and
		position.y < (_gameObject->getY() + _gameObject->getH()) and
		(position.x + w) > _gameObject->getX() and
		position.x < (_gameObject->getX() + _gameObject->getW());
}

bool GameObject::isDealDamage(Message* _message)
{
	return _message->messageType == MessageType::DEALDAMAGE and
		_message->dealDamage.gameObject == this ? true : false;
}

void GameObject::createMessage(GameObjectType _gameObjectType, Vector2f _position)
{
	Game::getInstance()->message(new Message(this,
		_gameObjectType,
		MessageType::CREATE,
		_position));
}

void GameObject::destroyMessage()
{
	if (!destroyed)
	{
		Game::getInstance()->message(new Message(this,
			MessageType::DESTROY));
		destroyed = true;
	}
}

void GameObject::emptyMessage()
{
	Game::getInstance()->message(new Message(this,
		MessageType::EMPTY));
}

void GameObject::setDirection(Direction _direction)
{
	direction = _direction;
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

void GameObject::setPositionInSprite(Vector2f _position)
{
	sprite.setPosition(_position);
}

GameObject::GameObject(Direction _direction, GameObjectType _gameObjectType, int _w, int _h, Texture* _texture, Vector2f _position)
{
	destroyed = false;
	direction = _direction;
	gameObjectType = _gameObjectType;
	w = _w;
	h = _h;
	sprite.setTexture(*_texture);
	position = _position;
	setDirection(_direction);
	setPositionInSprite(_position);
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