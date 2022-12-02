#include "..\include\DynamicObject.h"

void DynamicObject::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}

void DynamicObject::setDirection(Direction direction)
{
	this->direction = direction;

	if (this->direction == Direction::UP)
	{
		sprite.setRotation(0);
	}
	else if (this->direction == Direction::LEFT)
	{
		sprite.setRotation(270);
	}
	else if (this->direction == Direction::DOWN)
	{
		sprite.setRotation(180);
	}
	else if (this->direction == Direction::RIGHT)
	{
		sprite.setRotation(90);
	}
}
