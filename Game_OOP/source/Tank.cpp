#include "..\include\Tank.h"

Tank::Tank(float _velocity, Direction _direction, GameObjectType _gameObjectType, const char* _filename, Vector2f _position) : DynamicObject(_velocity, _direction, _gameObjectType, TANK_W, TANK_H, _filename, _position)
{
	healthPoints = TANK_HEALTHPOINTS;
	cooldown = TANK_COOLDOWN;
	cooldownTime = cooldown;
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

int Tank::getHealthPoints()
{
	return healthPoints;
}

bool Tank::readyToShoot(float _time)
{
	cooldown > cooldownTime ? cooldownTime += _time : cooldownTime = cooldown;

	return cooldown <= cooldownTime ? true : false;
}

void Tank::setHealthPoints(int _healthPoints)
{
	healthPoints = _healthPoints;
}

void Tank::shoot()
{
	if (cooldown <= cooldownTime)
	{
		sendMessageInGame(new Message(MessageType::SHOOT, this));
		cooldownTime = 0;
	}
}