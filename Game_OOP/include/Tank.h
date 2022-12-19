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
	bool readyToShoot(float _time);
	void shoot();
	int getHealthPoints();
	void setHealthPoints(int _healthPoints);
	void alive();
};

#endif // !_TANK_H