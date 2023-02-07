/**
 * This class describes my planet behavior.
 *
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 */

#include "planet.h"
#include "player.h"
#include <rt2d/entity.h>

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
	//ddCircle(this->position.x, this->position.y, 128,GREEN);

	//the scale of the planet
	this->scale = Point(0.5f, 0.5f);
}


Planet::~Planet()
{

}

void Planet::update(float deltaTime)
{	
	//Change the color of the planet
	if(this->health <= 50)
	{
		this->sprite()->color = CYAN;
	}
}

