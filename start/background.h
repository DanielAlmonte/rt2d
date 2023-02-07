/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file background.h
 *
 * @brief description of Background behavior.
 */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <rt2d/entity.h>

/// @brief The Background class is the Entity implementation.
class Background : public Entity
{
public:
	/// @brief Constructor
	Background();
	/// @brief Destructor
	virtual ~Background();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Background* background;

private:
	/* add your private declarations */
};


#endif /* BACKGROUND_H */
