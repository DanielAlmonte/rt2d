/**
 * This class describes my spawner behavior.
 *
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 */

#include <rt2d/entity.h>
#include "spawner.h"

using namespace std;

//Spawner
Spawner::Spawner(Planet* planet) : Entity()
{
	t.start();
	_planet = planet;
	//adds the sprite for the Spawner
	// this->addSprite("assets/Planet.tga");

	// this->scale = Point2(0.4, 0.4);

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
	// if (input()->getKeyDown(KeyCode::E))
	// {
	// 	enemy = new Enemy(_planet);
	// 	Point2 random = Point2(rand() % SWIDTH -350 , rand() % SHEIGHT-250);
	// 	this->parent()->addChild(enemy);
	// 	enemy->position = this->position + random;
	// 	enemies.push_back(enemy);
	// }

	if (t.seconds() > 5.25) 
	{
		enemy = new Enemy(_planet);
		Point2 random = Point2(rand() % SWIDTH -350 , rand() % SHEIGHT-250);
		this->parent()->addChild(enemy);
		enemy->position = this->position + random;
		enemies.push_back(enemy);
		t.start();
	}
}