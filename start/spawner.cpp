/**
 * This class describes my spawner behavior.
 *
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 */

#include "myentity.h"

using namespace std;

//Spawner
Spawner::Spawner() : Entity()
{
	//adds the sprite for the Spawner
	//this->addSprite("assets/Spawner.tga");

	//the color of the Spawner
	//this->sprite()->color = RED;		

	//the debug circle of the Spawner
	//ddCircle(this->position.x, this->position.y, 128,GREEN);
}


Spawner::~Spawner()
{

}

void Spawner::update(float deltaTime)
{

}