#ifndef _TANK_H
#define _TANK_H

#include "DynamicObject.h"

class Tank : public DynamicObject
{
private:
	float cooldown;
	float cooldownTime;
	int healthPoints;

public:
	Tank();
	void alive();
	int getHealthPoints();
	bool readyToShoot(float _time);
	void setHealthPoints(int _healthPoints);
	void shoot();
};

#endif // !_TANK_H