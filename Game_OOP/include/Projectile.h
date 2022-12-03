#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "DynamicObject.h"

class Projectile : public DynamicObject
{
private:
	int damage;

public:
	Projectile();
	void update(float time) override;
};

#endif // !_PROJECTILE_H
