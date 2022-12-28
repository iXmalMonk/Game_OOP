#include "..\include\Water.h"
#include "..\include\Game.h"

Water::Water(Vector2f _position) :
	StaticObject(GameObjectType::WATER,
		STATICOBJECT_SMALL_W,
		STATICOBJECT_SMALL_H,
		Game::getInstance()->getTexture(GameObjectType::WATER),
		_position) {}