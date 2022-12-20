#include "..\include\StaticObject.h"

StaticObject::StaticObject()
{
	w = STATICOBJECT_W;
	h = STATICOBJECT_H;
}

void StaticObject::receiveMessage(Message* _message)
{
	if (_message->dealDamage.gameObject == this)
	{
		destroy();
		if (MESSAGES_DEBUG_IN_STATICOBJECT)
			cout << "Static object destroyed" << endl;
	}
}

void StaticObject::update(float _time)
{
	move(getPosition());
}