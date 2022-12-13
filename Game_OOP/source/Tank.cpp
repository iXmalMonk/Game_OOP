#include "..\include\Tank.h"

Tank::Tank() : healthPoints(TANK_HEALTHPOINTS), cooldown(TANK_COOLDOWN), cooldownTime(cooldown)
{
	w = TANK_W;
	h = TANK_H;
}

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

void Tank::alive()
{
	if (healthPoints <= 0)
	{
		destroy();
		if (MESSAGES_DEBUG_IN_TANK)
			cout << "Tank destroyed" << endl;
	}
}