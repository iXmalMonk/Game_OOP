#ifndef _STATICOBJECT_H
#define _STATICOBJECT_H

#include "GameObject.h"

class StaticObject :
	public GameObject
{
public:
	StaticObject(GameObjectType _gameObjectType,
		int _w,
		int _h,
		Texture* _texture,
		Vector2f _position);
	static Vector2f getPositionOfADynamicObjectRelativeToAStaticObjectAfterCollision(GameObject* _dynamicObject,
		GameObject* _staticObject);
	virtual void message(Message* _message) override;
	void update(float _time) override;
};

#endif // !_STATICOBJECT_H