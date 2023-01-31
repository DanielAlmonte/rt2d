/**
 * This class describes my player bullet behavior.
 *
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 */

#include "bullet.h"
#include "player.h"

//Bullet
Bullet::Bullet() : Entity()
{
	//adds the sprite for the bullet
	this->addSprite("assets/Bullet.tga");

	//the color of the bullet
	this->sprite()->color = CYAN;

	//Debug circle
	//ddCircle(this->position.x, this->position.y, 8,GREEN);

	hit = false;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->position += bulletSpeed * Point2(cos(this->rotation.z), sin(this->rotation.z)) * deltaTime;

	if (t.seconds() > 0.00333f) 
	{
		RGBAColor color = this->sprite()->color;
		this->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}