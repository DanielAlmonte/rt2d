/**
 * This class describes my player behavior.
 *
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 */

#include "player.h"
using namespace std;


//Player
Player::Player() : Entity()
{
	movementSpeed = 300;
	this->addSprite("assets/SpaceShipTest.tga");
	this->sprite()->color = WHITE;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	//###############################################################
	// Movement test
	// ###############################################################

	//Up
	if (input()->getKey(KeyCode::W) || input()->getKey(KeyCode::Up)) 
	{
		this->position.y -= movementSpeed * deltaTime;
	}
	//Down
	if (input()->getKey(KeyCode::S) || input()->getKey(KeyCode::Down)) 
	{
		this->position.y += movementSpeed * deltaTime;
	}
	//Right
	if (input()->getKey(KeyCode::D) || input()->getKey(KeyCode::Right)) 
	{
		this->position.x += movementSpeed * deltaTime;
	}
	//Left
	if (input()->getKey(KeyCode::A) || input()->getKey(KeyCode::Left)) 
	{
		this->position.x -= movementSpeed * deltaTime;
	}

	//###############################################################
	// Bullet test
	// ###############################################################

	if (input()->getKeyDown(KeyCode::Space)) 
	{
        bullet = new Bullet();
        bullet->position = this->position - Point2(0,50);
        this->addChild(bullet);
        this->parent()->addChild(bullet);
        bullets.push_back(bullet);
	}

	
}

