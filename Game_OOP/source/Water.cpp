#include "..\include\Water.h"

Water::Water(Vector2f _position) : StaticObject(FILENAME_PNG_WATER, GameObjectType::WATER, STATICOBJECT_SMALL_W, STATICOBJECT_SMALL_H, _position) {}