#include "..\include\GameObject.h"
#include "..\include\Game.h"

Game* GameObject::instance = nullptr;

GameObject::GameObject()
{
	if (!instance) instance = Game::create();
}

Sprite GameObject::getSprite()
{
	return this->sprite;
}

void GameObject::sendMessage(Message* message)
{
	instance->receiveMessage(message);
}
