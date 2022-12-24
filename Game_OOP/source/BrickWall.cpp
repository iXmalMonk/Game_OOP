#include "..\include\BrickWall.h"

BrickWall::BrickWall(Vector2f _position) : StaticObject(FILENAME_PNG_BRICKWALL, GameObjectType::BRICKWALL, STATICOBJECT_SMALL_W, STATICOBJECT_SMALL_H, _position) {}