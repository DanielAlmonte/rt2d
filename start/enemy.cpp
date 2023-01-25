/**
 * This class describes the enemy behavior.
 *
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 */

#include "enemy.h"

Enemy::Enemy(Planet* planet) : Entity()
{
	//adds the spacehShip sprite for the enemy
    this->addSprite("assets/SpaceShip.tga");

	//the color of the player spaceShip
	this->sprite()->color = RED;

	//Debug circle
	ddCircle(this->position.x, this->position.y, 64,GREEN);
	health = 10;
	_planet = planet;
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	target = atan2(_planet->position.y - this->position.y, _planet->position.x - this->position.x);
	this->rotation.z = target;
	Point2 random = Point2(rand() % 60, rand() % 60);
	this->position += (random + Point2(30, 30))* Point2(cos(this->rotation.z), sin(this->rotation.z))* deltaTime;
}