#include "stdafx.h"
#include "enemy.h"
#include "player.h"

Enemy::Enemy(const string name, const string description, const int attack, const int defense, const int life) :
Entity(name, description)
{
	attackPoints = attack;
	defensePoints = defense;
	lifePoints = life;
}

int Enemy::receiveAttack(int playerAttackPoints)
{
	playerAttackPoints -= defensePoints;
	if (playerAttackPoints < 0) playerAttackPoints = 0;

	lifePoints = lifePoints - playerAttackPoints;
	return lifePoints;
}

void Enemy::attackPlayer(Player* player)
{
	player->receiveAttack(attackPoints);
}

Enemy::~Enemy()
{}