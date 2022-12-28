#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "DynamicObject.h"

class Projectile :
	public DynamicObject
{
private:
	GameObject* gameObjectWhoShooted;
	int damage;

	void dealDamage(GameObject* _gameObject,
		int _damage);
	Vector2f getPositionForProjectile(Direction _direction,
		Vector2f _position);

public:
	Projectile(Direction _direction,
		GameObject* _gameObjectWhoShooted,
		Vector2f _position);
	void message(Message* _message) override;
	void update(float _time) override;
};

#endif // !_PROJECTILE_H