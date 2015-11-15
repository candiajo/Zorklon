#pragma once

#include "entity.h"

class Player;

class Enemy : public Entity
{
public:
	Enemy(const string name, const string description, const int attack, const int defense, const int life);
	~Enemy();
	int receiveAttack(int attackPoints);
	void attackPlayer(Player* player);
	int lifePoints;

private:
	int attackPoints;
	int defensePoints;

};