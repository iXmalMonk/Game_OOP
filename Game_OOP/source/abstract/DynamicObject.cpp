#include "..\..\include\abstract\DynamicObject.h"

DynamicObject::DynamicObject(Direction _direction, float _velocity, GameObjectType _gameObjectType, int _w, int _h, Texture* _texture, Vector2f _position) :
	GameObject(_direction,
		_gameObjectType,
		_w,
		_h,
		_texture,
		_position)
{
	dx = 0;
	dy = 0;
	velocity = _velocity;
}

float DynamicObject::getVelocity()
{
	return velocity;
}