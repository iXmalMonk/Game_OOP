#ifndef _PLAYER_H
#define _PLAYER_H

#include "Tank.h"

class Player : public Tank
{
public:
	Player();
	void update(float _time) override;
	void receiveMessage(Message* _message) override;
};

#endif // !_PLAYER_H
