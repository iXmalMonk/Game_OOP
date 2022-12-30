#include "..\..\include\staticObjects\ConcreteWall.h"
#include "..\..\include\utilts\GameResources.h"

ConcreteWall::ConcreteWall(Vector2f _position) :
	StaticObject(GameObjectType::CONCRETEWALL,
		STATICOBJECT_SMALL_W,
		STATICOBJECT_SMALL_H,
		GameResources::getInstance()->getTexture(GameObjectType::CONCRETEWALL),
		_position) {}