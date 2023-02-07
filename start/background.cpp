/**
 * This class describes background behavior.
 *
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 */

#include "background.h"

Background::Background() : Entity()
{
    this->addSprite("assets/Background2.tga");
    //Pink, magenta, gray, orange
    this->sprite()->color = PINK;
    // this->scale = Point2(10, 10);		
}


Background::~Background()
{

}

void Background::update(float deltaTime)
{
	
}


