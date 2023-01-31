/**
 * This class describes my planet behavior.
 *
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 */

#include "planet.h"
#include "player.h"
#include "myentity.h"

using namespace std;

//Planet
Planet::Planet() : Entity()
{
	health = 100;
	//adds the sprite for the planet
	this->addSprite("assets/Planet.tga");

	//the color of the planet
	//this->sprite()->color = WHITE;		

	//the debug circle of the planet
	ddCircle(this->position.x, this->position.y, 128,GREEN);
}


Planet::~Planet()
{

}

void Planet::update(float deltaTime)
{
	if(this->health <= 50)
	{
		this->sprite()->color = CYAN;
	}
}

