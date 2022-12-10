#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject : public GameObject
{
protected:
	float velocity;
	float dx, dy;

public:
	DynamicObject();
};

#endif // !_DYNAMICOBJECT_H