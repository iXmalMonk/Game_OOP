#include "..\..\include\staticObjects\BrickWall.h"
#include "..\..\include\utilts\GameResources.h"

BrickWall::BrickWall(Vector2f _position) :
	StaticObject(GameObjectType::BRICKWALL,
		TEXTURE_WIDTH_AND_HEIGHT_32,
		TEXTURE_WIDTH_AND_HEIGHT_32,
		GameResources::getInstance()->getTexture(GameObjectType::BRICKWALL),
		_position) {}