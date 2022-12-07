#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "DynamicObject.h"

class Projectile : public DynamicObject
{
private:
	GameObjectType gameObjectTypeWhoShooted;
public:
	Projectile(Vector2f _position, Direction _direction, int _w, int _h, GameObjectType _gameObjectTypeWhoShooted);
	void update(float _time) override;
	void receiveMessage(Message* _message) override;
	GameObjectType getGameObjectTypeWhoShooted();
};

#endif // !_PROJECTILE_H
