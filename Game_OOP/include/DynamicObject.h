#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject : public GameObject
{
protected:
	float dx;
	float dy;
	float velocity;

public:
	DynamicObject(float _velocity, Direction _direction, GameObjectType _gameObjectType, int _w, int _h, const char* _filename, Vector2f _position);
};

#endif // !_DYNAMICOBJECT_H