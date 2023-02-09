/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file background.h
 *
 * @brief description of Start behavior.
 */

#ifndef START_H
#define START_H

#include <rt2d/entity.h>

/// @brief The Start class is the Entity implementation.
class Start : public Entity
{
public:
	/// @brief Constructor
	Start();
	/// @brief Destructor
	virtual ~Start();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Start* start;

private:
	/* add your private declarations */
};


#endif /* START_H */
