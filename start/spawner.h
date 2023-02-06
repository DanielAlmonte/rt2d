/**
 * Copyright 2023 Daniel Almonte <you@yourhost.com>
 *
 * @file spawner.h
 *
 * @brief description of the spawner behavior.
 */


#ifndef SPAWNER_H
#define SPAWNER_H

#include "myentity.h"
#include "enemy.h"
#include <rt2d/entity.h>
#include "planet.h"


//Spawner
class Spawner : public Entity
{
public:
	/// @brief Constructor
	Spawner(Planet* _planet);
	/// @brief Destructor
	virtual ~Spawner();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	std::vector <Enemy*> enemies;

private:
	/* add your private declarations */
	Enemy* enemy;

	Planet* _planet;

	Timer t;
};

#endif /* SPAWNER_H */

