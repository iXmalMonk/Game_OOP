#include "..\include\BrickWall.h"

BrickWall::BrickWall(Vector2f _position)
{
	position.x = _position.x;
	position.y = _position.y;
	texture.loadFromFile(FILENAME_PNG_BRICKWALL);
	sprite.setTexture(texture);
	gameObjectType = GameObjectType::BRICKWALL;

	setPosition(position);
}