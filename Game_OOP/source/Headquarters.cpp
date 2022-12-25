#include "..\include\Headquarters.h"

Headquarters::Headquarters(Vector2f _position) : StaticObject(FILENAME_PNG_HEADQUARTERS, GameObjectType::HEADQUARTERS, STATICOBJECT_BIG_W, STATICOBJECT_BIG_H, _position) {}

void Headquarters::message(Message* _message)
{
	if (_message->messageType == MessageType::DEALDAMAGE and
		_message->dealDamage.gameObject == this)
	{
		destroy();
		create(GameObjectType::FLAG, getPosition());
		if (MESSAGES_DEBUG_IN_HEADQUARTERS)
			cout << "Headquarters destroyed" << endl;
	}
}