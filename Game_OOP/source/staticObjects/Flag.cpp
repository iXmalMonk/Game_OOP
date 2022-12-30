#include "..\..\include\staticObjects\Flag.h"
#include "..\..\include\utilts\GameResources.h"

Flag::Flag(Vector2f _position) :
	StaticObject(GameObjectType::FLAG,
		STATICOBJECT_BIG_W,
		STATICOBJECT_BIG_H,
		GameResources::getInstance()->getTexture(GameObjectType::FLAG),
		_position) {}