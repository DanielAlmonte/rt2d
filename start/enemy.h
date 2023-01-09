/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file enemy.h
 *
 * @brief description of enemy behavior.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "myentity.h"

/// @brief The MyScene class is the Scene implementation.
class Enemy : public Entity
{
public:
	/// @brief Constructor
	Enemy();
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	

private:
	/// @brief the enemy that spawns
	Enemy* enemy;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* ENEMY_H */