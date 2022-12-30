#ifndef _PLAYER_H
#define _PLAYER_H

#include "..\abstract\Tank.h"

class Player :
	public Tank
{
public:
	Player(Vector2f _position);
	void update(float _time) override;
};

#endif // !_PLAYER_H