/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file player.h
 *
 * @brief description of the player behavior.
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
	
	/// @brief  list for the bullets
	std::vector<Bullet*> bullets;

	/// @brief the speed that the player moves at
	Vector2 velocity = Vector2(0.8, 1.2);


private:
	/* add your private declarations */

	/// @brief pointer to the player
	Player* player;

	/// @brief pointer to the spaceship bullets
	Bullet* bullet;
};

#endif /* PLAYER_H */

