#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "DynamicObject.h"

class Projectile : public DynamicObject
{
private:
	int damage;
	GameObjectType gameObjectTypeWhoShooted;
	GameObject* gameObjectWhoShooted;
public:
	Projectile(Vector2f _position, Direction _direction, GameObjectType _gameObjectTypeWhoShooted, GameObject* _gameObjectWhoShooted);
	void update(float _time) override;
	void receiveMessage(Message* _message) override;
	GameObjectType getGameObjectTypeWhoShooted();
};

#endif // !_PROJECTILE_H
