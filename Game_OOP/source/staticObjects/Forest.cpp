#include "..\..\include\staticObjects\Forest.h"
#include "..\..\include\utilts\GameResources.h"

Forest::Forest(Vector2f _position) :
	StaticObject(GameObjectType::FOREST,
		TEXTURE_WIDTH_AND_HEIGHT_32,
		TEXTURE_WIDTH_AND_HEIGHT_32,
		GameResources::getInstance()->getTexture(GameObjectType::FOREST),
		_position) {}