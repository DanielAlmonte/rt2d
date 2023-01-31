
/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file bullet.h
 *
 * @brief description of the bullets behavior.
 */



#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>

//Bullet
class Bullet : public Entity
{
public:
	/// @brief Constructor
	Bullet();
	/// @brief Destructor
	virtual ~Bullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	bool hit;

private:
	/* add your private declarations */
	
	/// @brief the speed of the bullets
	Point2 bulletSpeed = Point2(650, 650);

	Timer t;
};

#endif /* BULLET_H */