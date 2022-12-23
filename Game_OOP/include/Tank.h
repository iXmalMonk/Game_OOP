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
	Tank(const char* _filename, Direction _direction, float _velocity, GameObjectType _gameObjectType, Vector2f _position);
	void alive();
	int getHealthPoints();
	void message(Message* _message) override;
	bool readyToShoot(float _time);
	void setHealthPoints(int _healthPoints);
	void shoot();
};

#endif // !_TANK_H