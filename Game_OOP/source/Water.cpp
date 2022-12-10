#include "..\include\Water.h"

Water::Water(Vector2f _position)
{
	position.x = _position.x;
	position.y = _position.y;
	texture.loadFromFile(FILENAME_PNG_WATER);
	sprite.setTexture(texture);
	gameObjectType = GameObjectType::WATER;

	setPosition(position);
}