/**
 * Copyright 2022 Daniel Almonte <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
#define _USE_MATH_DEFINES

#include <cmath>
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

	Vector2 Velocity;

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
	/// @brief  list for the bullets
	std::vector<Bullet*> bullets;

	/// @brief the speed that the player moves at
	//Vector2 velocity = Vector2(400,450);

	/// @brief the speed that the player decelerates at
	//Vector2 decelaration = Vector2(50, 62,5);

	/// @brief the amouth of health that the player has
	//int playerHealth;


private:
	/* add your private declarations */

	/// @brief pointer to the player
	Player* player;

	/// @brief pointer to the spaceship bullets
	Bullet* bullet;

	float angle;
};

#endif /* PLAYER_H */

