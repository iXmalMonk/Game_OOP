#include "..\..\include\staticObjects\Headquarters.h"
#include "..\..\include\utilts\GameResources.h"

Headquarters::Headquarters(Vector2f _position) :
	StaticObject(GameObjectType::HEADQUARTERS,
		STATICOBJECT_BIG_W,
		STATICOBJECT_BIG_H,
		GameResources::getInstance()->getTexture(GameObjectType::HEADQUARTERS),
		_position) {}

void Headquarters::message(Message* _message)
{
	if (isDealDamage(_message))
	{
		createMessage(GameObjectType::FLAG,
			getPosition());
		destroyMessage();
	}
}