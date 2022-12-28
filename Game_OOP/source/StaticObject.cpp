#include "..\include\StaticObject.h"

StaticObject::StaticObject(GameObjectType _gameObjectType, int _w, int _h, Texture* _texture, Vector2f _position) :
	GameObject(Direction::NONE,
		_gameObjectType,
		_w,
		_h,
		_texture,
		_position) {}

Vector2f StaticObject::findPositionOfADynamicObjectRelativeToAStaticObjectAfterCollision(GameObject* _dynamicObject, GameObject* _staticObject)
{
	float topA = _dynamicObject->getY();
	float bottomA = _dynamicObject->getY() + _dynamicObject->getH();
	float leftA = _dynamicObject->getX();
	float rightA = _dynamicObject->getX() + _dynamicObject->getW();

	float topB = _staticObject->getY();
	float bottomB = _staticObject->getY() + _staticObject->getH();
	float leftB = _staticObject->getX();
	float rightB = _staticObject->getX() + _staticObject->getW();

	Vector2f position;

	switch (_dynamicObject->getDirection())
	{
	case Direction::UP:
		if (0 <= rightA - leftB and
			rightA - leftB <= COLLISION_RANGE_FOR_STATICOBJECT)
			position = { leftB - _dynamicObject->getW(),
			bottomB };
		else if (0 <= rightB - leftA and
			rightB - leftA <= COLLISION_RANGE_FOR_STATICOBJECT)
			position = { rightB,
			bottomB };
		else
			position = { _dynamicObject->getX(),
			bottomB };
		break;
	case Direction::DOWN:
		if (0 <= rightA - leftB and
			rightA - leftB <= COLLISION_RANGE_FOR_STATICOBJECT)
			position = { leftB - _dynamicObject->getW(),
			topB - _dynamicObject->getH() };
		else if (0 <= rightB - leftA and
			rightB - leftA <= COLLISION_RANGE_FOR_STATICOBJECT)
			position = { rightB,
			topB - _dynamicObject->getH() };
		else
			position = { _dynamicObject->getX(),
			topB - _dynamicObject->getH() };
		break;
	case Direction::LEFT:
		if (0 <= bottomA - topB and
			bottomA - topB <= COLLISION_RANGE_FOR_STATICOBJECT)
			position = { rightB,
			topB - _dynamicObject->getH() };
		else if (0 <= bottomB - topA and
			bottomB - topA <= COLLISION_RANGE_FOR_STATICOBJECT)
			position = { rightB,
			bottomB };
		else
			position = { rightB,
			_dynamicObject->getY() };
		break;
	case Direction::RIGHT:
		if (0 <= bottomA - topB and
			bottomA - topB <= COLLISION_RANGE_FOR_STATICOBJECT)
			position = { leftB - _dynamicObject->getW(),
			topB - _dynamicObject->getH() };
		else if (0 <= bottomB - topA and
			bottomB - topA <= COLLISION_RANGE_FOR_STATICOBJECT)
			position = { leftB - _dynamicObject->getW(),
			bottomB };
		else
			position = { leftB - _dynamicObject->getW(),
			_dynamicObject->getY() };
		break;
	}
	return position;
}

void StaticObject::message(Message* _message)
{
	if (_message->messageType == MessageType::DEALDAMAGE and
		_message->dealDamage.gameObject == this)
	{
		destroy();
		if (MESSAGES_DEBUG_IN_STATICOBJECT)
			cout << "Static object destroyed" << endl;
	}
}

void StaticObject::update(float _time)
{
	empty();
}