#include "..\include\Forest.h"

Forest::Forest(Vector2f _position)
{
	position.x = _position.x;
	position.y = _position.y;
	texture.loadFromFile(FILENAME_PNG_FOREST);
	sprite.setTexture(texture);
	gameObjectType = GameObjectType::FOREST;

	setPosition(position);
}