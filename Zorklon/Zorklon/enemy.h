#pragma once

#include "entity.h"

class Player;
class Room;

class Enemy : public Entity
{
public:
	Enemy(const char* name, const char* description, const int attack, const int defense, const int life);
	~Enemy();
	int receiveAttack(int attackPoints);
	void attackPlayer(Player* player) const;
	void Tick(Player* player);
	void enemyDead(Room* room) const;

	int lifePoints;

private:
	int attackPoints;
	int defensePoints;
};