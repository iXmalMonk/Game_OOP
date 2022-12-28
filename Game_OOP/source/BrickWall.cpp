#include "..\include\BrickWall.h"
#include "..\include\Game.h"

BrickWall::BrickWall(Vector2f _position) :
	StaticObject(GameObjectType::BRICKWALL,
		STATICOBJECT_SMALL_W,
		STATICOBJECT_SMALL_H,
		Game::getInstance()->getTexture(GameObjectType::BRICKWALL),
		_position) {}