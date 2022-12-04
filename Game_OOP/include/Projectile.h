#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "DynamicObject.h"

class Projectile : public DynamicObject
{
public:
	Projectile(Vector2f _position, Direction _direction);
	void update(float _time) override;
};

#endif // !_PROJECTILE_H
