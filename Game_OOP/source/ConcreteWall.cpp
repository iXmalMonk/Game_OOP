#include "..\include\ConcreteWall.h"

ConcreteWall::ConcreteWall(Vector2f _position)
{
	position.x = _position.x;
	position.y = _position.y;
	texture.loadFromFile(FILENAME_PNG_CONCRETEWALL);
	sprite.setTexture(texture);
	gameObjectType = GameObjectType::CONCRETEWALL;

	setPosition(position);
}
