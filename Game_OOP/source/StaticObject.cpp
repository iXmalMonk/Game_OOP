#include "..\include\StaticObject.h"

StaticObject::StaticObject()
{
	w = STATICOBJECT_W;
	h = STATICOBJECT_H;
}

void StaticObject::update(float _time)
{
	sendMessageInGame(new Message(MessageType::MOVE, this, getPosition()));
}

void StaticObject::receiveMessage(Message* _message)
{
	if (_message->dealDamage.gameObject == this)
		sendMessageInGame(new Message(MessageType::DESTROY, this));
}