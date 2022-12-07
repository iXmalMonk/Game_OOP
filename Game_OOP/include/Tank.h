#ifndef _TANK_H
#define _TANK_H

#include "DynamicObject.h"

class Tank : public DynamicObject
{
private:
	int healthPoints;
	float cooldown;
	float cooldownTime;
public:
	Tank();
	bool readyToShoot(float _time);
	void shoot();
};

#endif // !_TANK_H
