#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject : public GameObject
{
protected:
	float velocity;
	enum class Direction { UP, LEFT, DOWN, RIGHT };
	Direction direction;

public:
	void setPosition(Vector2f position);
	void setDirection(Direction direction);
};

#endif // !_DYNAMICOBJECT_H
