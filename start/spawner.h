/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file spawner.h
 *
 * @brief description of the spawner behavior.
 */


#ifndef SPAWNER_H
#define SPAWNER_H

#include "myentity.h"
#include <rt2d/entity.h>


//Spawner
class Spawner : public Entity
{
public:
	/// @brief Constructor
	Spawner();
	/// @brief Destructor
	virtual ~Spawner();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief pointer to the spawner
	Spawner* spawner;

private:
	/* add your private declarations */

};

#endif /* SPAWNER_H */

