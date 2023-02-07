/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file planet.h
 *
 * @brief description of the planet behavior.
 */


#ifndef PLANET_H
#define PLANET_H

#include "player.h"
#include <rt2d/entity.h>


//Planet
class Planet : public Entity
{
public:
	/// @brief Constructor
	Planet();
	/// @brief Destructor
	virtual ~Planet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief pointer to the player
	Player* player;

	int health;

private:
	/* add your private declarations */

};

#endif /* PLANET_H */