#ifndef _TANK_H
#define _TANK_H

#include "DynamicObject.h"

class Tank :
	public DynamicObject
{
private:
	float cooldownMaxTimeForShooting;
	float cooldownTimeForShooting;
	int healthPoints;

	void alive();
	bool guiltyOfCollidingWithAnotherTank(GameObject* _gameObject);
	int getHealthPoints();
	virtual void move(float _time) = 0;
	void setHealthPoints(int _healthPoints);

public:
	Tank(Direction _direction,
		float _velocity,
		GameObjectType _gameObjectType,
		Texture* _texture,
		Vector2f _position);
	void message(Message* _message) override;
	bool readyToShoot(float _time);
	void shoot();
};

#endif // !_TANK_H