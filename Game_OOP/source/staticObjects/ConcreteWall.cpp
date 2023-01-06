#include "..\..\include\staticObjects\ConcreteWall.h"
#include "..\..\include\utilts\GameResources.h"

ConcreteWall::ConcreteWall(Vector2f _position) :
	StaticObject(GameObjectType::CONCRETEWALL,
		TEXTURE_WIDTH_AND_HEIGHT_32,
		TEXTURE_WIDTH_AND_HEIGHT_32,
		GameResources::getInstance()->getTexture(GameObjectType::CONCRETEWALL),
		_position) {}