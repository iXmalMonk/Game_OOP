#include "..\include\GameObject.h"

#include "..\include\Game.h"

void GameObject::setPosition(Vector2f _position)
{
	sprite.setPosition(_position);
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

bool GameObject::checkCollisionWithGameObject(GameObject* _gameObject)
{
	return (position.y + h) >= _gameObject->getY() and
		position.y <= (_gameObject->getY() + _gameObject->getH()) and
		(position.x + w) >= _gameObject->getX() and
		position.x <= (_gameObject->getX() + _gameObject->getW());
}

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
