/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"
#include "myentity.h"
#include "player.h"
#include "bullet.h"
#include "planet.h"

using namespace std;

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/1.2);

	planet = new Planet();
	planet->position = Point2(SWIDTH/2, SHEIGHT/2);
	

	// create the scene 'tree'
	// add player to this Scene as a child.
	this->addChild(planet);
	this->addChild(player);
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(planet);

	// delete player from the heap (there was a 'new' in the constructor)
	delete player;
	delete planet;
}

void MyScene::update(float deltaTime)
{

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) 
	{
		this->stop();
	}
	
	// ###############################################################
	// Rotatie
	// ###############################################################

	float mx = input()->getMouseX();
	float my = input()->getMouseY();
	Point2 mouse = Point2(mx, my);

	ddClear();

	//Line between player and mouse
	ddLine(player->position.x, player->position.y, mx, my, GREEN);

	//Rotate player & bullets
	float angle = atan2(mouse.y - player->position.y, mouse.x - player->position.x);
	player->rotation.z = angle;
	

	// ###############################################################
	// Screen Edges
	// ###############################################################

	//Border
	
	//X Axis
	if (player -> position.x + player->sprite()->size.x /2 > SWIDTH)
	{
		player->position.x += -1;
	}
	if (player -> position.x - player->sprite()->size.x /2  < 0)
	{
		player->position.x -= -1;
	}

	//Y Axis
	if (player -> position.y + player->sprite()->size.y /2 > SHEIGHT)
	{
		player->position.y += -1;
	}
	if (player -> position.y - player->sprite()->size.y /2  < 0)
	{
		player->position.y -= -1;
	}

	//Decelaration test

	// //X Axis
	// if (player -> position.x + player->sprite()->size.x /2 > SWIDTH)
	// {
	// 	player->position.x  -= decelaration.x;
	// }
	// if (player -> position.x - player->sprite()->size.x /2  < 0)
	// {
	// 	player->position.x += decelaration.x;
	// }

	// //Y Axis Down
	// // if (player -> position.y + player->sprite()->size.y /2 > SHEIGHT+ 50)
	// // {
	// // 	player->position.y -= decelaration.y;
	// // }

	// //Y Axis Top
	// if (player -> position.y - player->sprite()->size.y /2  < 50)
	// {
	// 	player->position.y  += decelaration.y;
	// }


	// if (player -> position.y - player->sprite()->size.y /2  < -60)
	// {
	// 	player->position.y  -=  decelaration.y * -1;
	// }

	//Teleport

	//X Axis
	// if(player ->position.x > SWIDTH)
	// {
	// 	player ->position.x = 0;
	// }

	// else if (player ->position.x <0)
	// {
	// 	player ->position.x = SWIDTH;
	// }
	
	//Y Axis
	// if(player ->position.y > SHEIGHT)
	// {
	// 	player ->position.y = 0;
	// }

	// else if (player ->position.y <0)
	// {
	// 	player ->position.y = SHEIGHT;
	// }
	

	// ###############################################################
	// Delete Bullets
	// ###############################################################
	
	for (int i = player->bullets.size() - 1; i >= 0; i--) 
	{ 
        if (player->bullets[i]->position.x > SWIDTH || player->bullets[i]->position.x < 0 || player->bullets[i]->position.y < 0 || player->bullets[i]->position.y > SHEIGHT)
        {
            this->removeChild(player->bullets[i]);
            delete player->bullets[i];
            player->bullets.erase(player->bullets.begin() + i);
            cout << "delete bullet" << endl;
        }
    }

	// ###############################################################
	// Collision detection
	// ###############################################################
	
	// the disntace between the planet and the player
	Vector2 distance =  Vector2(planet->position - player->position);
	float d = distance.getLength();

	//the radius of the planet
	// float rw = planet->sprite()->width() /2;
	// float rh = planet->sprite()->height() /2;
	// float r = rw + rh /2;
	float r = (planet->sprite()->width() /2) + (planet->sprite()->height() /2) /2;
	//cout<<r<<endl;  

	if (d < r)
	{
		player->line()->color = RED;
		planet->line()->color = RED;
		player->velocity = Vector2 (0.2 , 0.4);
	}
	else if (d < r + 40 )
	{
		player->line()->color = ORANGE;
		planet->line()->color = ORANGE;
		//planet->sprite()->color = RED;
		player->velocity = Vector2 (0.4 , 0.8);
	}
	
	else if (d > r)
	{
		player->line()->color = GREEN;
		planet->line()->color = GREEN;
		//planet->sprite()->color = WHITE;
		player->velocity = Vector2(0.8, 1.2);
	}
	//cout<<player->velocity<<endl;
}
