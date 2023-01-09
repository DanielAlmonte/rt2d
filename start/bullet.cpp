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
	this->addSprite("assets/Bullet.tga");
	this->sprite()->color = BLUE;
	
	// Line s2;
	// //Top line left corner
	// s2.addPoint(-5, -7);
	
	// //Right top corner
	// s2.addPoint(5, -7);
	
	// //Right bottom corner
	// s2.addPoint(5, 7);
	
	// //Left bottom corner
	// s2.addPoint(-5, 7);

	// //Left top corner
	// s2.addPoint(-5, -7);

	// this->addLine(&s2);
	// this->line()->color = GREEN;

	//Debug circle
	ddCircle(this->position.x, this->position.y, 8,GREEN);
}


Bullet::~Bullet()
{

}



void Bullet::update(float deltaTime)
{
	//this->position.y -= bulletSpeed * deltaTime;

	this->position += bulletSpeed * Point2(cos(this->rotation.z), sin(this->rotation.z)) * deltaTime;

	if (t.seconds() > 0.00333f) 
	{
		RGBAColor color = this->sprite()->color;
		this->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}