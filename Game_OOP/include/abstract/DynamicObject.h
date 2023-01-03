#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject :
	public GameObject
{
private:
	virtual void move(float _time) = 0;

protected:
	float dx;
	float dy;
	float velocity;

public:
	DynamicObject(Direction _direction,
		float _velocity,
		GameObjectType _gameObjectType,
		int _w,
		int _h,
		Texture* _texture,
		Vector2f _position);
};

#endif // !_DYNAMICOBJECT_H