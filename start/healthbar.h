/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file planet.h
 *
 * @brief description of the planet behavior.
 */


#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <rt2d/entity.h>


//Healthbar
class Healthbar : public Entity
{
public:
	/// @brief Constructor
	Healthbar();
	/// @brief Destructor
	virtual ~Healthbar();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */

};

#endif /* HEALTHBAR_H */