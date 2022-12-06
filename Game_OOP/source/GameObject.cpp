#include "..\include\GameObject.h"

void GameObject::sendMessage(MessageType _messageType)
{
	messages.push_back(new Message(_messageType, this));
}

list<GameObject::Message*> GameObject::getMessages()
{
	return messages;
}

Sprite GameObject::getSprite()
{
	return sprite;
}

void GameObject::setPosition(Vector2f _position)
{
	sprite.setPosition(_position);
}

Vector2f GameObject::getPosition()
{
	return position;
}

void GameObject::setDirection()
{
	switch (direction)
	{
	case Direction::UP:
		sprite.setTextureRect(IntRect(0, 0, w, h));
		break;
	case Direction::DOWN:
		sprite.setTextureRect(IntRect(w * 2, 0, w, h));
		break;
	case Direction::LEFT:
		sprite.setTextureRect(IntRect(w * 1, 0, w, h));
		break;
	case Direction::RIGHT:
		sprite.setTextureRect(IntRect(w * 3, 0, w, h));
		break;
	}
}

GameObject::Direction GameObject::getDirection()
{
	return direction;
}

int GameObject::getW()
{
	return w;
}

int GameObject::getH()
{
	return h;
}
