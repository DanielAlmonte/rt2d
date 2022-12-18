
/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of my player bullets behavior.
 */



#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>

//Bullet
class Bullet : public Entity
{

//Planet
public:
	/// @brief Constructor
	Bullet();
	/// @brief Destructor
	virtual ~Bullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	/// @brief the speed of the bullets
	Point2 bulletSpeed = Point2(500, 500);

	Timer t;
};

#endif /* BULLET_H */