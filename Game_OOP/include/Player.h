#ifndef _PLAYER_H
#define _PLAYER_H

#include "Tank.h"

class Player : public Tank
{
public:
	Player(Vector2f _position);
	void message(Message* _message) override;
	void update(float _time) override;
};

#endif // !_PLAYER_H