/**
 * This class describes MyScene behavior.
 *
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include <rt2d/entity.h>
#include "myscene.h"
#include "player.h"
#include "bullet.h"
#include "planet.h"
#include "enemy.h"

using namespace std;

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	lt.start();

	damage = 5;
	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	background = new Background();
	background->position = Point2(SWIDTH/2, SHEIGHT/2);

	spacehero = new Start();
	spacehero->position = Point2(700, 680);

	scoreboard = new Text();
	scoreboard->scale = Point2(0.5f, 0.5f);
	scoreboard->position = Point2(600, 20);

	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/1.2);

	planet = new Planet();
	planet->position = Point2(SWIDTH/2, SHEIGHT/2);

	redbarNet = new Healthbar();
	redbarNet->position = Point2(SWIDTH/2, 710);

	greenbar = new Healthbar();
	greenbar->position = Point2(SWIDTH/2, 710);

	redbarYer = new Healthbar();
	redbarYer->position = Point2(SWIDTH/2, 700);

	cyanbar = new Healthbar();
	cyanbar->position = Point2(SWIDTH/2, 700);

	// healthbar = new HealthBar();
	// healthbar->position = Point2(SWIDTH/2, SHEIGHT/2);

	// spawn = new Spawner(planet);
	// spawn->position = Point2(SWIDTH/3, SHEIGHT/3);

	TRSpawner = new Spawner(planet);
	TRSpawner->position = Point2(1500, -500);

	TLSpawner = new Spawner(planet);
	TLSpawner->position = Point2(-500, -500);
	
	BRSpawner = new Spawner(planet);
	BRSpawner->position = Point2(1500, 1000);
	
	BLSpawner = new Spawner(planet);
	BLSpawner->position = Point2(-500, 1000);
	
	spawners.push_back(TRSpawner);
	spawners.push_back(TLSpawner);
	spawners.push_back(BRSpawner);
	spawners.push_back(BLSpawner);


	// create the scene 'tree'
	// add player, enemy and planet to this Scene as a child.
	this->addChild(background);
	this->addChild(scoreboard);
	this->addChild(planet);
	this->addChild(player);
	this->addChild(redbarNet);
	this->addChild(greenbar);
	this->addChild(redbarYer);
	this->addChild(cyanbar);
	this->addChild(spacehero);

	this->addChild(TRSpawner);
	this->addChild(TLSpawner);
	this->addChild(BRSpawner);
	this->addChild(BLSpawner);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(spacehero);
	this->removeChild(player);
	this->removeChild(planet);
	this->removeChild(background);
	this->removeChild(scoreboard);
	this->removeChild(redbarNet);
	this->removeChild(greenbar);
	this->removeChild(redbarYer);
	this->removeChild(cyanbar);
	this->removeChild(TRSpawner);
	this->removeChild(TLSpawner);
	this->removeChild(BRSpawner);
	this->removeChild(BLSpawner);

	// deletes the player, the planet and the enemy from the heap (there was a 'new' in the constructor)
	delete player;
	delete planet;
	delete background;
	delete spacehero;
	delete scoreboard;
	delete redbarNet;
	delete greenbar;
	delete redbarYer;
	delete cyanbar;
	delete TRSpawner;
	delete TLSpawner;
	delete BRSpawner;
	delete BLSpawner;
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
	//ddLine(player->position.x, player->position.y, mx, my, CYAN);

	//Rotate player & bullets
	float angle = atan2(mouse.y - player->position.y, mouse.x - player->position.x);
	player->rotation.z = angle;

	// ###############################################################
	// Screen Edges
	// ###############################################################

	if (player->maxSpeed == 500)
	{
		this->kickBack = -12;
	}
	else
	{
		this->kickBack = -6;
	}
	//Border
	
	//X Axis
	if (player -> position.x + player->sprite()->size.x /2 > SWIDTH - 55)
	{
		player->acceleration.x += this->kickBack;
		cout<<1<<endl;
	}
	if (player -> position.x - player->sprite()->size.x /2  < 55)
	{
		player->acceleration.x -= this->kickBack;
		cout<<2<<endl;
	}

	//Y Axis
	if (player -> position.y + player->sprite()->size.y /2 > SHEIGHT - 55)
	{
		player->acceleration.y += this->kickBack;
		cout<<3<<endl;
	}
	if (player -> position.y - player->sprite()->size.y /2  < 55)
	{
		player->acceleration.y -= this->kickBack;
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
	// Delete Bullets Or Enemies
	// ###############################################################

	//checks for every bullet
	for (int i = player->bullets.size() - 1; i >= 0; i--)
	{ 
		//makes the bullet pointer, a pointer to the bullet in the list
		Bullet* bullet = player->bullets[i]; 

		//checks every spawner
		for (int e = spawners.size() - 1; e >= 0; e--)
		{ 
			//checks for each spawner the emenies that have been spawn
			for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--)
			{
				//makes the enemy pointer, a pointer to the enemies that have been spawn
				Enemy* enemy = spawners[e]->enemies[i]; 

				//if the enemy is not a null pointer
				if (enemy != nullptr)
				{	
					//removes the bullets if it is out of the screen
					if (bullet->position.x > SWIDTH || bullet->position.x < 0 || bullet->position.y < 0 || bullet->position.y > SHEIGHT)
					{
						bullet->hit = true;
					}

					//detects if the bullet has hit the enemy
					if (Vector2(bullet->position - enemy->position).getLengthSquared() < 16 * 16)//32
					{
						enemy->health -= damage;
						cout<<enemy->health<<endl;
						bullet->hit = true;
					}

					//removes the enemy if it doesn't have any health left
					if (enemy->health <= 0)
					{ 
						this->removeChild(enemy);
						delete enemy;
						enemy = nullptr;
						spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
						score++;
						cout<<score<<endl;
					}
				}
			}
		}

		//removes the bullet if its not a null pointer
		if (bullet->hit && bullet != nullptr)
		{
			this->removeChild(bullet);
			delete bullet;
			bullet = nullptr;
			player->bullets.erase(player->bullets.begin() + i);
			std::cout << "delete bullets" << std::endl;
		}
	}

	//checks every spawner
	for (int e = spawners.size() - 1; e >= 0; e--)
	{
		//checks for each spawner the emenies that have been spawn
		for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--)
		{
			//makes the enemy pointer, a pointer to the enemies that have been spawn
			Enemy* enemy = spawners[e]->enemies[i];

			//if the enemy and the planet are not a null pointer
			if (enemy != nullptr && planet != nullptr)
			{
				////detects if the enemy has hit the planet
				if (Vector2(planet->position - enemy->position).getLengthSquared() < 81 * 81)//162
				{
					planet->health -= damage;
					cout<<planet->health<<endl;
					this->removeChild(enemy);
					delete enemy;
					enemy = nullptr;
					spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
					greenbar->scale.x -= scalebarNet;
				}
			}

			if (enemy != nullptr && player != nullptr)
			{
				////detects if the enemy has hit the player
				if (Vector2(player->position - enemy->position).getLengthSquared() < 32 * 32)//64
				{
					player->health -= damage;
					cout<<player->health<<endl;
					this->removeChild(enemy);
					delete enemy;
					enemy = nullptr;
					spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
					cyanbar->scale.x -= scalebarYer;
				}
			}
		}
	}
	
	//removes the planet if it doesn't have any health left
	if (planet != nullptr && planet->health <= 0) {
		this->removeChild(planet);
		delete planet;
		planet = nullptr;
	}

	//removes the player if it doesn't have any health left
	if (player != nullptr && player->health <= 0) {
		this->removeChild(player);
		delete player;
		player = nullptr;
	}

	// ###############################################################
	// Collision detection
	// ###############################################################
	
	//the disntace between the planet and the player
	Vector2 distance =  Vector2(planet->position - player->position);
	float d = distance.getLength();

	//the radius of the planet
	float r = (planet->sprite()->width() /4.8) + (planet->sprite()->height() /4.8) /2;
	
	//detects if the distance is smaller than the radius
	if (d < r)
	{
		// player->line()->color = RED;
		// planet->line()->color = RED;
		player->acceleration = player->acceleration * -3;
	}
	
	//detects if the distance is bigger than the radius
	else if (d > r)
	{
		// player->line()->color = GREEN;
		// planet->line()->color = GREEN;
		player->velocity = player->velocity.getNormalized();
	}

	// ###############################################################
	// Healthbar & Scoreboard colors
	// ###############################################################

	//Healthbar
	greenbar->sprite()->color = GREEN;
	redbarNet->sprite()->color = RED;
	cyanbar->sprite()->color = CYAN;
	redbarYer->sprite()->color = RED;


	//Scoreboard
	std::stringstream clicktxt;
	clicktxt << "score: " << score;
	scoreboard->message(clicktxt.str(), CYAN);

	
	// ###############################################################
	// Start SpaceHero
	// ###############################################################
	
	if (t.seconds() > 0.0333f) 
	{
		RGBAColor color = spacehero->sprite()->color;
		spacehero->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}

	if (lt.seconds() > 0 && lt.seconds() < 4)
	{
		spacehero->scale -= Point2(0.00035, 0.00035);
		spacehero->position.y -= 0.13;
		spacehero->position.x -= 0.007;
	}
	
	if (lt.seconds() > 4.5)
	{
		spacehero->sprite()->color = BLACK;
		t.stop();
	}
	
	if (lt.seconds() > 5)
	{
		spacehero->position.x += 0.6;
	}

	if (lt.seconds() > 7.8)
	{
		this->removeChild(spacehero);
		delete spacehero;
		spacehero = nullptr;
		lt.stop();
	}
}