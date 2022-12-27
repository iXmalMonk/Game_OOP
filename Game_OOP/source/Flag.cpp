#include "..\include\Flag.h"
#include "..\include\Game.h"

Flag::Flag(Vector2f _position) : StaticObject(GameObjectType::FLAG, STATICOBJECT_BIG_W, STATICOBJECT_BIG_H, Game::getInstance()->getTexture(GameObjectType::FLAG), _position) {}