#include "..\include\StaticObject.h"

StaticObject::StaticObject(GameObjectType _gameObjectType, const char* _filename, Vector2f _position) : GameObject(Direction::NONE, _gameObjectType, STATICOBJECT_W, STATICOBJECT_H, _filename, _position) {}

void StaticObject::message(Message* _message)
{
	if (_message->messageType == MessageType::DEALDAMAGE and
		_message->dealDamage.gameObject == this)
	{
		destroy();
		if (MESSAGES_DEBUG_IN_STATICOBJECT)
			cout << "Static object destroyed" << endl;
	}
}

void StaticObject::update(float _time)
{
	empty();
}