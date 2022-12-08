#include "..\include\Tank.h"

Tank::Tank() : healthPoints(100), cooldown(15000), cooldownTime(cooldown) {}

bool Tank::readyToShoot(float _time)
{
	cooldown > cooldownTime ? cooldownTime += _time : cooldownTime = cooldown;

	return cooldown <= cooldownTime ? true : false;
}

void Tank::shoot()
{
	if (cooldown <= cooldownTime)
	{
		sendMessageInGame(new Message(MessageType::SHOOT, this));
		cooldownTime = 0;
	}
}

int Tank::getHealthPoints()
{
	return healthPoints;
}

void Tank::setHealthPoints(int _healthPoints)
{
	healthPoints = _healthPoints;
}
