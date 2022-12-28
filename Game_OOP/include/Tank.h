#ifndef _TANK_H
#define _TANK_H

#include "DynamicObject.h"

class Tank :
	public DynamicObject
{
private:
	float cooldown;
	float cooldownTime;
	int healthPoints;

public:
	Tank(Direction _direction,
		float _velocity,
		GameObjectType _gameObjectType,
		Texture* _texture,
		Vector2f _position);
	void alive();
	bool guiltyOfCollidingWithAnotherTank(GameObject* _gameObject);
	int getHealthPoints();
	void message(Message* _message) override;
	bool readyToShoot(float _time);
	void setHealthPoints(int _healthPoints);
	void shoot();
};

#endif // !_TANK_H