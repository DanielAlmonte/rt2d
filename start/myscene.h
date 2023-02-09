/**
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>

#include "background.h"
#include "start.h"
#include "player.h"
#include "planet.h"
#include "bullet.h"
#include "enemy.h"
#include "spawner.h"
#include "healthbar.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
	/// @brief the angle used to rotate the player
	float angle;

	int kickBack;
	float targetPlayer;
	float targetPlanet;

	int damage;

private:

	Background* background;

	Start* spacehero;
	
	Text* scoreboard;

	/// @brief the spaceship that the player moves
	Player* player;

	/// @brief the spaceship of the enemy
	Enemy* enemy;

	/// @brief the planet in the middle of the screen
	Planet* planet;

	/// @brief Pointer to the bullet
	Bullet* bullet;

	Healthbar* greenbar;
	Healthbar* redbarYer;
	Healthbar* redbarNet;
	Healthbar* cyanbar;
	Healthbar* scorebarcyan;
	Healthbar* scorebarblue;

	float scalebarNet = 0.1;
	float scalebarYer = 0.2;
	int score = 0;
	int de = .1;
	
	std::vector <Spawner*> spawners;

	/// @brief Pointer to the spawners
	Spawner* TRSpawner;
	Spawner* TLSpawner;
	Spawner* BRSpawner;
	Spawner* BLSpawner;
	bool remove;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	Timer l;
	Timer lt;
};

#endif /* SCENE00_H */
