#include "stdafx.h"
#include "enemy.h"
#include "player.h"

Enemy::Enemy(const char* name, const char* description, const int attack, const int defense, const int life) :
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

void Enemy::attackPlayer(Player* player) const
{
	player->receiveAttack(attackPoints);
}

void Enemy::Tick(Player* player)
{
	if (name == "goblin3")
	{
		Item* meat = dynamic_cast<Item*>(player->currentRoom->extractItem("meat"));
		
		if (meat != NULL)
		{
			cout << "The big GOBLIN jumps out of his hole and eats the rotten MEAT. He stands in front of you and it's still hungry...\n";
			attackPoints = 25;
			defensePoints = 4;
			lifePoints -= meat->usePoints;
			if (meat->usePoints > 0) cout << "The POISON of the MEAT hurts the GOBLIN, it loses " << meat->usePoints << " points. Now it has " << lifePoints << " points of life.\n";
			description = "A big GOBLIN that doesn't seem to be your friend.\n";
			delete (meat);
		}
		cout << endl << "The GOBLIN attacks you.\n";
		attackPlayer(player);
	}
	else if (name == "boss")
	{
		cout << "The huge MONSTER attacks you.\n";
		attackPlayer(player);
	}
}

void Enemy::enemyDead(Room* room) const
{
	cout << "The enemy has been killed.\n";
	if (name == "boss")	cout << "You defeated the big guardian, you won the game! Congratulations!.\n";
	else if (name == "goblin3")
	{
		Item* greenKey = new Item("greenkey", "A big dirty green key (I'll call it GREENKEY), you can OPEN doors with green locks.");
		room->addItem(greenKey);

		cout << "The dead goblin has droped something.\n";
		cout << "A big dirty green key (I'll call it GREENKEY), you can OPEN doors with green locks.";
	}
}

Enemy::~Enemy()
{}