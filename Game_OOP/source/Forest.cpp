#include "..\include\Forest.h"
#include "..\include\Game.h"

Forest::Forest(Vector2f _position) : StaticObject(GameObjectType::FOREST, STATICOBJECT_SMALL_W, STATICOBJECT_SMALL_H, Game::getInstance()->getTexture(GameObjectType::FOREST), _position) {}