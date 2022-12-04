#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject : public GameObject
{
protected:
	float velocity;

	enum class Direction { UP, DOWN, LEFT, RIGHT };
	Direction direction;

public:
	void setDirection(Direction _direction);
};

#endif // !_DYNAMICOBJECT_H
