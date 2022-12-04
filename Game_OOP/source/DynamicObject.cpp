#include "..\include\DynamicObject.h"

void DynamicObject::setDirection(Direction _direction)
{
	if (direction == Direction::UP)
		sprite.setTextureRect(IntRect(0, 0, w, h));
	else if (direction == Direction::DOWN)
		sprite.setTextureRect(IntRect(w * 2, 0, w, h));
	else if (direction == Direction::LEFT)
		sprite.setTextureRect(IntRect(w * 1, 0, w, h));
	else if (direction == Direction::RIGHT)
		sprite.setTextureRect(IntRect(w * 3, 0, w, h));
}