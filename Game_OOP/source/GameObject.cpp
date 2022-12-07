#include "..\include\GameObject.h"

#include "..\include\Game.h"

Game* GameObject::instance = nullptr;

GameObject::GameObject() : position(), texture(), sprite(), w(0), h(0), gameObjectType(GameObjectType::NONE), direction(Direction::NONE)
{
	instance = Game::getInstance();
}

void GameObject::sendMessageInGame(Message* _message)
{
	instance->receiveMessage(_message);
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

float GameObject::getX()
{
	return position.x;
}

float GameObject::getY()
{
	return position.y;
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

GameObject::GameObjectType GameObject::getGameObjectType()
{
	return gameObjectType;
}
