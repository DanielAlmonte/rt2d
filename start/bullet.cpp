/**
 * This class describes my player bullet behavior.
 *
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 */

#include <vector>
#include "bullet.h"
#include "player.h"

//Bullet
Bullet::Bullet() : Entity()
{
	bulletSpeed = 500;
	this->addSprite("assets/BulletTest.tga");
	this->sprite()->color = GREEN;
}


Bullet::~Bullet()
{

}



void Bullet::update(float deltaTime)
{
	this->position.y -= bulletSpeed * deltaTime;
}