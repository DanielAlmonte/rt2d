/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"
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
	player->position = Point2(640, 540);

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
	this->removeChild(player);

	// delete player from the heap (there was a 'new' in the constructor)
	delete player;
	delete planet;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales player
	// ###############################################################
	// if (input()->getKeyDown(KeyCode::Space)) {
	// 	player->scale = Point(0.5f, 0.5f);
	// }
	// if (input()->getKeyUp(KeyCode::Space)) {
	// 	player->scale = Point(1.0f, 1.0f);
	// }

	
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
	// Bullets
	// ###############################################################
	
	for (int i = player->bullets.size() - 1; i >= 0; i--) 
	{ 
        if (player->bullets[i]->position.x > SWIDTH || player->bullets[i]->position.x < 0 || player->bullets[i]->position.y < 0 || player->bullets[i]->position.y > SHEIGHT)
        {
            this->removeChild(player->bullets[i]);
            delete player->bullets[i];
            player->bullets.erase(player->bullets.begin() + i);
            std::cout << "delete bullet" << std::endl;
        }
    }

	

	// ###############################################################
	// Rotate color
	// ###############################################################
	// if (t.seconds() > 0.0333f) {
	// 	RGBAColor color = player->sprite()->color;
	// 	player->sprite()->color = Color::rotate(color, 0.01f);
	// 	t.start();
	// }
}
