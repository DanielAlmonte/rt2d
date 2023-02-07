#pragma once
/**
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 *
 * @file enemy.h
 *
 * @brief description of enemy behavior.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include "planet.h"

/// @brief The MyScene class is the Scene implementation.
class Enemy : public Entity
{
public:
	/// @brief Constructor
	Enemy(Planet* _planet);
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
	int health;
	

private:
	
	Planet* _planet;

	Player* player;

	float target;

	
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* ENEMY_H */
#pragma once