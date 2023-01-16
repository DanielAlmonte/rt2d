/**
 * This class describes MyScene behavior.
 *
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"
#include "myentity.h"
#include "player.h"
#include "bullet.h"
#include "planet.h"
#include "enemy.h"

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

	enemy= new Enemy();
	enemy->position = Point2(SWIDTH/2, SHEIGHT/2);
	

	// create the scene 'tree'
	// add player, enemy and planet to this Scene as a child.
	this->addChild(planet);
	this->addChild(player);
	this->addChild(enemy);
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(planet);
	this->removeChild(enemy);

	// deletes the player, the planet and the enemy from the heap (there was a 'new' in the constructor)
	delete player;
	delete planet;
	delete enemy;
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

	//gets the X and Y position of the mouse
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
	if (player -> position.x + player->sprite()->size.x /2 > SWIDTH - 50)
	{
		player->acceleration.x += -5;
		cout<<1<<endl;
	}
	if (player -> position.x - player->sprite()->size.x /2  < 50)
	{
		player->acceleration.x -= -5;
		cout<<2<<endl;
	}

	//Y Axis
	if (player -> position.y + player->sprite()->size.y /2 > SHEIGHT - 55)
	{
		player->acceleration.y += -6;
		cout<<3<<endl;
	}
	if (player -> position.y - player->sprite()->size.y /2  < 55)
	{
		player->acceleration.y -= -6;
		cout<<4<<endl;
	}

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
		//the disntace between the enemy and the bullet
		Vector2 distance =  Vector2(enemy->position - player->bullets[i]->position);
		float d = distance.getLength();

		//the radius of the enemy
		float r = (enemy->sprite()->width() /2) + (enemy->sprite()->height() /2) /2;


		if (d < r)
		{
			removeChild(enemy);
		}

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
	
	//the disntace between the planet and the player
	Vector2 distance =  Vector2(planet->position - player->position);
	float d = distance.getLength();

	//the radius of the planet
	float r = (planet->sprite()->width() /2) + (planet->sprite()->height() /2) /2;

	//detects if the distance is smaller than the radius
	if (d < r)
	{
		player->line()->color = RED;
		planet->line()->color = RED;
		player->acceleration = player->acceleration * -5;
	}
	
	//detects if the distance is bigger than the radius
	else if (d > r)
	{
		player->line()->color = GREEN;
		planet->line()->color = GREEN;
		player->velocity = player->velocity.getNormalized();
	}
}
