#include "..\include\ConcreteWall.h"
#include "..\include\Game.h"

ConcreteWall::ConcreteWall(Vector2f _position) :
	StaticObject(GameObjectType::CONCRETEWALL,
		STATICOBJECT_SMALL_W,
		STATICOBJECT_SMALL_H,
		Game::getInstance()->getTexture(GameObjectType::CONCRETEWALL),
		_position) {}