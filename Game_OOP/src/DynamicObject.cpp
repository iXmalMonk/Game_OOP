#include "..\include\DynamicObject.h"

void DynamicObject::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}

void DynamicObject::setDirection(Direction direction)
{
	if (this->direction == Direction::UP)
		this->sprite.setTextureRect(IntRect(0, 0, this->w, this->h));
	else if (this->direction == Direction::LEFT)
		this->sprite.setTextureRect(IntRect(this->w * 1, 0, this->w, this->h));
	else if (this->direction == Direction::DOWN)
		this->sprite.setTextureRect(IntRect(this->w * 2, 0, this->w, this->h));
	else if (this->direction == Direction::RIGHT)
		this->sprite.setTextureRect(IntRect(this->w * 3, 0, this->w, this->h));
}
