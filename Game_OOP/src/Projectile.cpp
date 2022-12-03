#include "..\include\Projectile.h"

Projectile::Projectile()
{
	this->position.x = 0;
	this->position.y = 0;
	this->texture.loadFromFile("png/projectile.png");
	this->sprite.setTexture(this->texture);
	this->w = 16;
	this->h = 16;
	this->velocity = 0.05;
	this->direction = Direction::DOWN;
	this->damage = 50;
}

void Projectile::update(float time)
{
	if (this->direction == Direction::UP)
		this->position.y -= this->velocity * time;
	if (this->direction == Direction::LEFT)
		this->position.x -= this->velocity * time;
	if (this->direction == Direction::DOWN)
		this->position.y += this->velocity * time;
	if (this->direction == Direction::RIGHT)
		this->position.x += this->velocity * time;

	setDirection(this->direction);
	setPosition(this->position);
}
