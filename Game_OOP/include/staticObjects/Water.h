#ifndef _WATER_H
#define _WATER_H

#include "..\abstract\StaticObject.h"

class Water :
	public StaticObject
{
public:
	Water(Vector2f _position);
};

#endif // !_WATER_H