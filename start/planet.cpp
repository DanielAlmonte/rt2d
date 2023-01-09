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
	//this->addCircleSprite(("assets/Planet.tga"), 64 , 16);
	this->addSprite("assets/Planet.tga");
	this->sprite()->color = WHITE;		

	// Line s3;
	// //Top line left corner
	// s3.addPoint(-64, -64);
	
	// //Right top corner
	// s3.addPoint(64, -64);
	
	// //Right bottom corner
	// s3.addPoint(64, 64);
	
	// //Left bottom corner
	// s3.addPoint(-64, 64);

	// //Left top corner
	// s3.addPoint(-64, -64);

	// this->addLine(&s3);
	// this->line()->color = GREEN;

	//Debug circle
	ddCircle(this->position.x, this->position.y, 128,GREEN);
}


Planet::~Planet()
{

}

void Planet::update(float deltaTime)
{

	// ###############################################################
	// Rotate
	// ###############################################################
	// this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	// if (this->rotation.z > TWO_PI) 
	// {
	// 	this->rotation.z -= TWO_PI;
	// }
}

