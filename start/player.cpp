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
	this->addSprite("assets/SpaceShip.tga");
	this->sprite()->color = BLUE;

	// Line s1;
	// //Top line left corner
	// s1.addPoint(-32, -32);
	
	// //Right top corner
	// s1.addPoint(32, -32);
	
	// //Right bottom corner
	// s1.addPoint(32, 32);
	
	// //Left bottom corner
	// s1.addPoint(-32, 32);

	// //Left top corner
	// s1.addPoint(-32, -32);

	// this->addLine(&s1);
	// this->line()->color = GREEN;

	//Debug circle
	ddCircle(this->position.x, this->position.y, 64,GREEN);
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	//###############################################################
	// Movement
	// ###############################################################
	this->position += velocity * deltaTime;
	//Up
	if (input()->getKey(KeyCode::W) || input()->getKey(KeyCode::Up)) 
	{
		this->position.y -= velocity.y;
	}
	//Down
	if (input()->getKey(KeyCode::S) || input()->getKey(KeyCode::Down)) 
	{
		this->position.y += velocity.y;
	}
	//Right
	if (input()->getKey(KeyCode::D) || input()->getKey(KeyCode::Right)) 
	{
		this->position.x += velocity.x;
	}
	//Left
	if (input()->getKey(KeyCode::A) || input()->getKey(KeyCode::Left)) 
	{
		this->position.x -= velocity.x;
	}

	// //Up
	// if (input()->getKey(KeyCode::W) || input()->getKey(KeyCode::Up)) 
	// {
	// 	this->position -= Vector2(0, 1.2);
	// }
	// //Down
	// if (input()->getKey(KeyCode::S) || input()->getKey(KeyCode::Down)) 
	// {
	// 	this->position += Vector2(0, 1.2);
	// }
	// //Right
	// if (input()->getKey(KeyCode::D) || input()->getKey(KeyCode::Right)) 
	// {
	// 	this->position += Vector2(0.8, 0);
	// }
	// //Left
	// if (input()->getKey(KeyCode::A) || input()->getKey(KeyCode::Left)) 
	// {
	// 	this->position -= Vector2(0.8, 0);
	// }

	// //Right
	// if (input()->getKey(KeyCode::D) || input()->getKey(KeyCode::Right)) 
	// {
	// 	this->position += Vector2(0.3, 0);
	// }
	// //Left
	// if (input()->getKey(KeyCode::A) || input()->getKey(KeyCode::Left)) 
	// {
	// 	this->position -= Vector2(0.3, 0);
	// }

	float mx = input()->getMouseX();
	float my = input()->getMouseY();
	Point2 mouse = Point2(mx, my);

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
}

