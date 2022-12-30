#include "..\..\include\staticObjects\BrickWall.h"
#include "..\..\include\utilts\GameResources.h"

BrickWall::BrickWall(Vector2f _position) :
	StaticObject(GameObjectType::BRICKWALL,
		STATICOBJECT_SMALL_W,
		STATICOBJECT_SMALL_H,
		GameResources::getInstance()->getTexture(GameObjectType::BRICKWALL),
		_position) {}