#ifndef _STATICOBJECT_H
#define _STATICOBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject();
	void update(float _time) override;
	void receiveMessage(Message* _message) override;
};

#endif // !_STATICOBJECT_H


