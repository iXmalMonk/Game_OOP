#include "..\include\ConcreteWall.h"

ConcreteWall::ConcreteWall(Vector2f _position) : StaticObject(FILENAME_PNG_CONCRETEWALL, GameObjectType::CONCRETEWALL, STATICOBJECT_SMALL_W, STATICOBJECT_SMALL_H, _position) {}