#include "..\include\StaticObject.h"

StaticObject::CollisionStaticObject::CollisionStaticObject(CollisionSideOfDynamicObject _collisionSideOfDynamicObject, Vector2f _position)
{
	collisionSideOfDynamicObject = _collisionSideOfDynamicObject;
	position = _position;
}

StaticObject::CollisionStaticObject StaticObject::checkCollisionOfDynamicObjectWithStaticObject(GameObject* _dynamicObject, GameObject* _staticObject)
{
	float topA = _dynamicObject->getY();
	float bottomA = _dynamicObject->getY() + _dynamicObject->getH();
	float leftA = _dynamicObject->getX();
	float rightA = _dynamicObject->getX() + _dynamicObject->getW();

	float topB = _staticObject->getY();
	float bottomB = _staticObject->getY() + _staticObject->getH();
	float leftB = _staticObject->getX();
	float rightB = _staticObject->getX() + _staticObject->getW();

	switch (_dynamicObject->getDirection())
	{
	case Direction::UP:
		if (0 <= rightA - leftB and rightA - leftB < COLLISION_RANGE_FOR_STATIC_OBJECT)
			return CollisionStaticObject(CollisionSideOfDynamicObject::TOP, Vector2f(leftB - _dynamicObject->getW(), bottomB));
		else if (0 <= rightB - leftA and rightB - leftA < COLLISION_RANGE_FOR_STATIC_OBJECT)
			return CollisionStaticObject(CollisionSideOfDynamicObject::TOP, Vector2f(rightB, bottomB));
		else
			return CollisionStaticObject(CollisionSideOfDynamicObject::TOP, Vector2f(_dynamicObject->getX(), bottomB));
		break;
	case Direction::DOWN:
		if (0 <= rightA - leftB and rightA - leftB < COLLISION_RANGE_FOR_STATIC_OBJECT)
			return CollisionStaticObject(CollisionSideOfDynamicObject::BOTTOM, Vector2f(leftB - _dynamicObject->getW(), topB - _dynamicObject->getH()));
		else if (0 <= rightB - leftA and rightB - leftA < COLLISION_RANGE_FOR_STATIC_OBJECT)
			return CollisionStaticObject(CollisionSideOfDynamicObject::BOTTOM, Vector2f(rightB, topB - _dynamicObject->getH()));
		else
			return CollisionStaticObject(CollisionSideOfDynamicObject::BOTTOM, Vector2f(_dynamicObject->getX(), topB - _dynamicObject->getH()));
		break;
	case Direction::LEFT:
		if (0 <= bottomA - topB and bottomA - topB < COLLISION_RANGE_FOR_STATIC_OBJECT)
			return CollisionStaticObject(CollisionSideOfDynamicObject::LEFT, Vector2f(rightB, topB - _dynamicObject->getH()));
		else if (0 <= bottomB - topA and bottomB - topA < COLLISION_RANGE_FOR_STATIC_OBJECT)
			return CollisionStaticObject(CollisionSideOfDynamicObject::LEFT, Vector2f(rightB, bottomB));
		else
			return CollisionStaticObject(CollisionSideOfDynamicObject::LEFT, Vector2f(rightB, _dynamicObject->getY()));
		break;
	case Direction::RIGHT:
		if (0 <= bottomA - topB and bottomA - topB < COLLISION_RANGE_FOR_STATIC_OBJECT)
			return CollisionStaticObject(CollisionSideOfDynamicObject::RIGHT, Vector2f(leftB - _dynamicObject->getW(), topB - _dynamicObject->getH()));
		else if (0 <= bottomB - topA and bottomB - topA < COLLISION_RANGE_FOR_STATIC_OBJECT)
			return CollisionStaticObject(CollisionSideOfDynamicObject::RIGHT, Vector2f(leftB - _dynamicObject->getW(), bottomB));
		else
			return CollisionStaticObject(CollisionSideOfDynamicObject::RIGHT, Vector2f(leftB - _dynamicObject->getW(), _dynamicObject->getY()));
		break;
	}
}

StaticObject::StaticObject(const char* _filename, GameObjectType _gameObjectType, int _w, int _h, Vector2f _position) : GameObject(_filename, Direction::NONE, _gameObjectType, _w, _h, _position) {}

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