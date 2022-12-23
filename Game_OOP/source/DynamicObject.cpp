#include "..\include\DynamicObject.h"

DynamicObject::DynamicObject(const char* _filename, Direction _direction, float _velocity, GameObjectType _gameObjectType, int _w, int _h, Vector2f _position) : GameObject(_filename, _direction, _gameObjectType, _w, _h, _position)
{
	dx = 0;
	dy = 0;
	velocity = _velocity;
}

float DynamicObject::getVelocity()
{
	return velocity;
}