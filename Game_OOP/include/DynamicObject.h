#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject :
	public GameObject
{
private:
	float velocity;

protected:
	float dx;
	float dy;

public:
	DynamicObject(Direction _direction,
		float _velocity,
		GameObjectType _gameObjectType,
		int _w,
		int _h,
		Texture* _texture,
		Vector2f _position);
	float getVelocity();
};

#endif // !_DYNAMICOBJECT_H