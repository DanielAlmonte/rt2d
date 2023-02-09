/**
 * This class describes start behavior.
 *
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 */

#include "start.h"

Start::Start() : Entity()
{
    this->addSprite("assets/SpaceHero4.tga");
    //Pink, magenta, gray, orange
    this->sprite()->color = CYAN;
    this->scale = Point2(1.22, 1.22);		
}


Start::~Start()
{

}

void Start::update(float deltaTime)
{
	
}


