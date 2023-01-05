#include "..\..\include\abstract\StaticObject.h"

StaticObject::StaticObject(GameObjectType _gameObjectType, int _w, int _h, Texture* _texture, Vector2f _position) :
	GameObject(Direction::NONE,
		_gameObjectType,
		_w,
		_h,
		_texture,
		_position) {}

Vector2f StaticObject::getPositionOfADynamicObjectRelativeToAStaticObjectAfterCollision(GameObject* _dynamicObject, GameObject* _staticObject)
{
	float topD = _dynamicObject->getY();
	float bottomD = _dynamicObject->getY() + _dynamicObject->getH();
	float leftD = _dynamicObject->getX();
	float rightD = _dynamicObject->getX() + _dynamicObject->getW();
	float topS = _staticObject->getY();
	float bottomS = _staticObject->getY() + _staticObject->getH();
	float leftS = _staticObject->getX();
	float rightS = _staticObject->getX() + _staticObject->getW();
	Vector2f position;
	switch (_dynamicObject->getDirection())
	{
	case Direction::UP:
		if (0 <= rightD - leftS and
			rightD - leftS <= STATICOBJECT_COLLISION_RANGE)
			position = { leftS - _dynamicObject->getW(),
				bottomS };
		else if (0 <= rightS - leftD and
			rightS - leftD <= STATICOBJECT_COLLISION_RANGE)
			position = { rightS,
				bottomS };
		else
			position = { _dynamicObject->getX(),
				bottomS };
		break;
	case Direction::DOWN:
		if (0 <= rightD - leftS and
			rightD - leftS <= STATICOBJECT_COLLISION_RANGE)
			position = { leftS - _dynamicObject->getW(),
				topS - _dynamicObject->getH() };
		else if (0 <= rightS - leftD and
			rightS - leftD <= STATICOBJECT_COLLISION_RANGE)
			position = { rightS,
				topS - _dynamicObject->getH() };
		else
			position = { _dynamicObject->getX(),
				topS - _dynamicObject->getH() };
		break;
	case Direction::LEFT:
		if (0 <= bottomD - topS and
			bottomD - topS <= STATICOBJECT_COLLISION_RANGE)
			position = { rightS,
				topS - _dynamicObject->getH() };
		else if (0 <= bottomS - topD and
			bottomS - topD <= STATICOBJECT_COLLISION_RANGE)
			position = { rightS, 
				bottomS };
		else
			position = { rightS,
				_dynamicObject->getY() };
		break;
	case Direction::RIGHT:
		if (0 <= bottomD - topS and
			bottomD - topS <= STATICOBJECT_COLLISION_RANGE)
			position = { leftS - _dynamicObject->getW(),
				topS - _dynamicObject->getH() };
		else if (0 <= bottomS - topD and
			bottomS - topD <= STATICOBJECT_COLLISION_RANGE)
			position = { leftS - _dynamicObject->getW(),
				bottomS };
		else
			position = { leftS - _dynamicObject->getW(),
				_dynamicObject->getY() };
		break;
	}
	return position;
}

void StaticObject::message(Message* _message)
{
	if (isDealDamage(_message))
		destroyMessage();
}

void StaticObject::update(float _time)
{
	emptyMessage();
}