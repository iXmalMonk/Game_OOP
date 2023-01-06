#include "..\..\include\staticObjects\Water.h"
#include "..\..\include\utilts\GameResources.h"

Water::Water(Vector2f _position) :
	StaticObject(GameObjectType::WATER,
		TEXTURE_WIDTH_AND_HEIGHT_32,
		TEXTURE_WIDTH_AND_HEIGHT_32,
		GameResources::getInstance()->getTexture(GameObjectType::WATER),
		_position) {}