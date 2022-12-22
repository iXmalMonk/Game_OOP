#include "..\include\DynamicObject.h"

DynamicObject::DynamicObject(float _velocity, Direction _direction, GameObjectType _gameObjectType, int _w, int _h, const char* _filename, Vector2f _position) : GameObject(_direction, _gameObjectType, _w, _h, _filename, _position)
{
	dx = 0;
	dy = 0;
	velocity = _velocity;
}