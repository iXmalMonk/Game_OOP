#include "..\include\Headquarters.h"
#include "..\include\Game.h"

Headquarters::Headquarters(Vector2f _position) :
	StaticObject(GameObjectType::HEADQUARTERS,
		STATICOBJECT_BIG_W,
		STATICOBJECT_BIG_H,
		Game::getInstance()->getTexture(GameObjectType::HEADQUARTERS),
		_position) {}

void Headquarters::message(Message* _message)
{
	if (_message->messageType == MessageType::DEALDAMAGE and
		_message->dealDamage.gameObject == this)
	{
		destroy();
		create(GameObjectType::FLAG,
			getPosition());
		if (MESSAGES_DEBUG_IN_STATICOBJECT)
			cout << "Headquarters destroyed" << endl;
	}
}