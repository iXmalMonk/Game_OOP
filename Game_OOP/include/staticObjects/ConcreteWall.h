#ifndef _CONCRETEWALL_H
#define _CONCRETEWALL_H

#include "..\abstract\StaticObject.h"

class ConcreteWall :
	public StaticObject
{
public:
	ConcreteWall(Vector2f _position);
};

#endif // !_CONCRETEWALL_H