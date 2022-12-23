#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject : public GameObject
{
private:
	float velocity;

protected:
	float dx;
	float dy;

public:
	DynamicObject(float _velocity, Direction _direction, GameObjectType _gameObjectType, int _w, int _h, const char* _filename, Vector2f _position);
	float getVelocity();
};

#endif // !_DYNAMICOBJECT_H