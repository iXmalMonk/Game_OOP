#ifndef _STATICOBJECT_H
#define _STATICOBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	enum class CollisionSideOfDynamicObject { TOP, BOTTOM, LEFT, RIGHT, NONE };
	struct CollisionStaticObject
	{
		CollisionSideOfDynamicObject collisionSideOfDynamicObject;
		Vector2f position;

		CollisionStaticObject(CollisionSideOfDynamicObject _collisionSideOfDynamicObject, Vector2f _position);
	};

	static CollisionStaticObject checkCollisionOfDynamicObjectWithStaticObject(GameObject* _dynamicObject, GameObject* _staticObject);
	StaticObject(const char* _filename, GameObjectType _gameObjectType, int _w, int _h, Vector2f _position);
	virtual void message(Message* _message) override;
	void update(float _time) override;
};

#endif // !_STATICOBJECT_H