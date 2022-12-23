#ifndef _ENEMY_H
#define _ENEMY_H

#include "Tank.h"

class Enemy : public Tank
{
public:
	Enemy(Vector2f _position);
	void message(Message* _message) override;
	void update(float _time) override;
};

#endif // !_ENEMY_H