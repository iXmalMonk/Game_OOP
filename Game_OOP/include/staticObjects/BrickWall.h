#ifndef _BRICKWALL_
#define _BRICKWALL_

#include "..\abstract\StaticObject.h"

class BrickWall :
	public StaticObject
{
public:
	BrickWall(Vector2f _position);
};

#endif // !_BRICKWALL_