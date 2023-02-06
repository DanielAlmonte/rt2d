/**
 * This class describes my healthbar behavior.
 *
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 */

#include "healthbar.h"
#include "myentity.h"

using namespace std;

//Healthbar
Healthbar::Healthbar() : Entity()
{
	
	//adds the sprite for the healthbar
	this->addSprite("assets/Rectangle.tga");
	
	//the color of the healthbar
	//this->sprite()->color = WHITE;

	this->scale.x += 1.06;
	this->scale.y -= 0.3;
}


Healthbar::~Healthbar()
{

}

void Healthbar::update(float deltaTime)
{	
	
	
}

