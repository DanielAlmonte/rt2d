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

#include "myentity.h"
#include "player.h"
#include "planet.h"
#include "bullet.h"
#include "enemy.h"

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

private:
	/// @brief the spaceship that the player moves
	Player* player;

	/// @brief the spaceship of the enemy
	Enemy* enemy;

	/// @brief the planet in the middle of the screen
	Planet* planet;

	/// @brief Pointer to the bullet
	Bullet* bullet;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
