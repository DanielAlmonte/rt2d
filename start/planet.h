/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */


#ifndef PLANET_H
#define PLANET_H

#include "myentity.h"
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

	/// @brief the amouth of health that the planet has
	//int planetHealth;

	Player* player;

private:
	/* add your private declarations */
	
};

#endif /* PLANET_H */