#pragma once

#include "entity.h"
#include "room.h"

#include <string>

class Item;

class Player : public Entity
{
public:
	Player(const char* name, const char* description, const int attackPoins, const int defensePoints, const int lifePoints);
	~Player();

	void Do(const string word1, const string word2);
	bool isDead() const;
	void receiveAttack(int enemyAttackPoints);

	Room* currentRoom;
	bool winGame;

private:
	returnsType getItem(const string item, Entity* owner);
	returnsType putItem(const string item, Entity* newOwner);
	void clearEnemy(Room* enemyRoom);
	void exitRoom();
	int itemsEquiped() const;
	void tickEnemy();

	void Look(const string item) const;
	void Go(const string direction);
	void Open(const string item);
	void Take(const string item);
	void Leave(const string item);
	void Equip(const string item);
	void Store(const string item);
	void Attack(const string item);
	void Upgrade(const string item);
	void Poison(const string item);
	void showHelp() const;

	DirectionType directionWatching;
	const int maxItemsEquiped = 4;
	int attackPoints;
	int defensePoints;
	int lifePoints;
};