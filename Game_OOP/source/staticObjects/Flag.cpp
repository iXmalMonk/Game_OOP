#include "..\..\include\staticObjects\Flag.h"
#include "..\..\include\utilts\GameResources.h"

Flag::Flag(Vector2f _position) :
	StaticObject(GameObjectType::FLAG,
		TEXTURE_WIDTH_AND_HEIGHT_64,
		TEXTURE_WIDTH_AND_HEIGHT_64,
		GameResources::getInstance()->getTexture(GameObjectType::FLAG),
		_position) {}