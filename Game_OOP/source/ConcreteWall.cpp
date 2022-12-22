#include "..\include\ConcreteWall.h"

ConcreteWall::ConcreteWall(Vector2f _position) : StaticObject(GameObjectType::BRICKWALL, FILENAME_PNG_CONCRETEWALL, _position) {}