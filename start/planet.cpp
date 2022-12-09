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
	this->addSprite("assets/PlanetTest.tga");
}

Planet::~Planet()
{

}

void Planet::update(float deltaTime)
{
	//###############################################################
	// Player, Planet and Enemy collider
	// ###############################################################
	
	// if (player->sprite()->width() /2 +  planet->sprite()->width() /2 > 100)
	// {
	// 	cout << "interaction";
	// }

	// else if (player->position != planet -> position)
	// {
	// 	cout << "interaction false";
	// }

	// ###############################################################
	// Rotate
	// ###############################################################
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}
}

