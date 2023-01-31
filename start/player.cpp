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
	health = 50;
	//adds the spacehShip sprite for the player
	this->addSprite("assets/SpaceShip.tga");

	//the color of the player spaceShip
	this->sprite()->color = CYAN;

	//the debug circle of the player
	//ddCircle(this->position.x, this->position.y, 64,GREEN);

	//the scale of the player
	this->scale = Point(0.5f, 0.5f);
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	//###############################################################
	// Movement
	// ###############################################################
	
	this->velocity += this->acceleration;
	this->position += this->velocity * deltaTime;

	//Up
	if (input()->getKey(KeyCode::W) || input()->getKey(KeyCode::Up)) 
	{
		this->acceleration.y -= this->decceleration.y;
	}
	//Down
	if (input()->getKey(KeyCode::S) || input()->getKey(KeyCode::Down)) 
	{
		this->acceleration.y += this->decceleration.y;
	}
	//Right
	if (input()->getKey(KeyCode::D) || input()->getKey(KeyCode::Right)) 
	{
		this->acceleration.x += this->decceleration.x;
	}
	//Left
	if (input()->getKey(KeyCode::A) || input()->getKey(KeyCode::Left)) 
	{
		this->acceleration.x -= this->decceleration.x;
	}

	//the max speed of the player
	if (this->acceleration.getLength() > maxSpeed)
	{
		this->acceleration = this->acceleration.getNormalized();
		this->acceleration *= maxSpeed;
	}

	//gets the X and Y position of the mouse
	float mx = input()->getMouseX();
	float my = input()->getMouseY();
	Point2 mouse = Point2(mx, my);

	//the rotation
	float angle = atan2(mouse.y - this->position.y, mouse.x - this->position.x);
	this->rotation.z = angle;

	//###############################################################
	// Create Bullets
	// ###############################################################

	if (input()->getKeyDown(KeyCode::Space) || input()->getMouseDown(0)) 
	{
        bullet = new Bullet();
        bullet->position = this->position;
		//bullet->position = this->position - Point2(0, 32);
		bullet->rotation.z = angle;
       	//this->addChild(bullet);
        this->parent()->addChild(bullet);
        bullets.push_back(bullet);
	}

	// if(this->health <= 25)
	// {
	// 	this->sprite()->color = BLUE;
	// }

	if (input()->getKey(KeyCode::LeftShift) || input()->getKey(KeyCode::RightShift)) 
	{
		this->maxSpeed = 500;
	}

	else
	{
		this->maxSpeed = 300;
	}
}

