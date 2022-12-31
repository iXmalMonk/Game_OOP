#ifndef _ENEMY_H
#define _ENEMY_H

#include "..\abstract\Tank.h"

class Enemy :
	public Tank
{
private:
	float cooldownMaxTimeForRandomDirection;
	float cooldownTimeForRandomDirection;

	void move(float _time) override;
	void randomDirection(float _time);

public:
	Enemy(Vector2f _position);
	void update(float _time) override;
};

#endif // !_ENEMY_H