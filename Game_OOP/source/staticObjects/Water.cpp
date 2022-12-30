#include "..\..\include\staticObjects\Water.h"
#include "..\..\include\utilts\GameResources.h"

Water::Water(Vector2f _position) :
	StaticObject(GameObjectType::WATER,
		STATICOBJECT_SMALL_W,
		STATICOBJECT_SMALL_H,
		GameResources::getInstance()->getTexture(GameObjectType::WATER),
		_position) {}