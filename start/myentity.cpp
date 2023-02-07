/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"

MyEntity::MyEntity() : Entity()
{
    this->addSprite("assets/Background2.tga");
    //Pink, magenta, gray, orange
    this->sprite()->color = PINK;
    // this->scale = Point2(10, 10);		
}


MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{
	
}


