/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */


#ifndef PLAYER_H
#define PLAYER_H

#include "bullet.h"
#include <rt2d/entity.h>

//Player
class Player : public Entity
{
public:
	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
	/// @brief the speed that the player moves at
	int movementSpeed;
	std::vector<Bullet*> bullets;

private:
	/* add your private declarations */
	/// @brief pointer to the spaceship bullets
	Bullet* bullet;
};

#endif /* PLAYER_H */

