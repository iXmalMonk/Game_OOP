#include "..\include\Tank.h"

Tank::Tank() : cooldown(15000), cooldownTime(cooldown) {}

bool Tank::readyToShoot(float _time)
{
	cooldown > cooldownTime ? cooldownTime += _time : cooldownTime = cooldown;

	return cooldown <= cooldownTime ? true : false;
}

void Tank::shoot()
{
	if (cooldown <= cooldownTime)
	{
		sendMessage(MessageType::SHOOT);
		cooldownTime = 0;
	}
}
