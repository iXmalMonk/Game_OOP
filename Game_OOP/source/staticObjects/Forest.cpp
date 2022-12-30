#include "..\..\include\staticObjects\Forest.h"
#include "..\..\include\utilts\GameResources.h"

Forest::Forest(Vector2f _position) :
	StaticObject(GameObjectType::FOREST,
		STATICOBJECT_SMALL_W,
		STATICOBJECT_SMALL_H,
		GameResources::getInstance()->getTexture(GameObjectType::FOREST),
		_position) {}