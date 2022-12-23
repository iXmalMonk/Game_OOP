#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "DynamicObject.h"

class Projectile : public DynamicObject
{
private:
	GameObject* gameObjectWhoShooted;
	int damage;

	void dealDamage(GameObject* _gameObject, int _damage);
	Vector2f getPositionForProjectile(Vector2f _position, Direction _direction);

public:
	Projectile(Vector2f _position, Direction _direction, GameObject* _gameObjectWhoShooted);
	void receiveMessage(Message* _message) override;
	void update(float _time) override;
};

#endif // !_PROJECTILE_H