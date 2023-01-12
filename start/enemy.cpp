/**
 * This class describes the enemy behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "enemy.h"

Enemy::Enemy() : Entity()
{
    this->addSprite("assets/SpaceShip.tga");
	this->sprite()->color = RED;

	//Debug circle
	ddCircle(this->position.x, this->position.y, 64,GREEN);
}


Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	
}