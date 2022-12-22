#ifndef _STATICOBJECT_H
#define _STATICOBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject(GameObjectType _gameObjectType, const char* _filename, Vector2f _position);
	void receiveMessage(Message* _message) override;
	void update(float _time) override;
};

#endif // !_STATICOBJECT_H