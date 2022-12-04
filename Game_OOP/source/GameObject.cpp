#include "..\include\GameObject.h"

#include "..\include\Game.h" //

Game* GameObject::instance = nullptr; //

GameObject::GameObject() : position(), texture(), sprite(), w(0), h(0)
{
	instance = Game::create(); //
}

void GameObject::sendMessage(Message* _message)
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