#ifndef _ENEMY_H
#define _ENEMY_H

#include "Tank.h"

class Enemy : public Tank
{
public:
	Enemy();
	void update(float time) override;
};

#endif // !_ENEMY_H
