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

	bool guiltyOfCollidingWithAnotherTank(GameObject* _gameObject);
	bool isDead();

public:
	Tank(Direction _direction,
		float _velocity,
		GameObjectType _gameObjectType,
		Texture* _texture,
		Vector2f _position);
	bool isReadyToShoot(float _time);
	void message(Message* _message) override;
	void shoot();
};

#endif // !_TANK_H