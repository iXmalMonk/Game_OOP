#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "..\abstract\DynamicObject.h"

class Projectile :
	public DynamicObject
{
private:
	GameObject* gameObjectWhoShooted;
	GameObjectType gameObjectTypeWhoShooted;
	int damage;

	Vector2f getPositionForProjectile(Direction _direction,
		Vector2f _position);
	void dealDamageMessage(GameObject* _gameObject,
		int _damage);
	void move(float _time) override;

public:
	Projectile(Direction _direction,
		GameObject* _gameObjectWhoShooted,
		GameObjectType _gameObjectTypeWhoShooted,
		Vector2f _position);
	void message(Message* _message) override;
	void update(float _time) override;
};

#endif // !_PROJECTILE_H