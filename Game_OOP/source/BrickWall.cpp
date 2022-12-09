#include "..\include\BrickWall.h"

BrickWall::BrickWall(Vector2f _position)
{
	position.x = _position.x;
	position.y = _position.y;
	texture.loadFromFile(BRICKWALL_FILENAME_PNG);
	sprite.setTexture(texture);
	gameObjectType = GameObjectType::BRICKWALL;

	setPosition(position);
}
