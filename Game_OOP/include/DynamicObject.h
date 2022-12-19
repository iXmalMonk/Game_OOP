#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject : public GameObject
{
protected:
	float dx, dy;
	float velocity;

public:
	DynamicObject();
};

#endif // !_DYNAMICOBJECT_H