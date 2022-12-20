#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "DynamicObject.h"

class Projectile : public DynamicObject
{
private:
	GameObjectType gameObjectTypeWhoShooted;
	GameObject* gameObjectWhoShooted;
	int damage;

public:
	Projectile(Vector2f _position, Direction _direction, GameObjectType _gameObjectTypeWhoShooted, GameObject* _gameObjectWhoShooted);
	GameObjectType getGameObjectTypeWhoShooted();
	void receiveMessage(Message* _message) override;
	void update(float _time) override;
};

#endif // !_PROJECTILE_H