#include "..\include\GameObject.h"

#include "..\include\Game.h" //

Game* GameObject::instance = nullptr; //

GameObject::GameObject() : position(), texture(), sprite(), w(0), h(0)
{
	instance = Game::create(); //
}

void GameObject::sendMessage(Message* message)
{
	instance->receiveMessage(message);
}