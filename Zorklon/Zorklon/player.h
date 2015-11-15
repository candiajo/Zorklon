#pragma once

#include "entity.h"
#include "room.h"

#include <string>

class Item;

class Player : public Entity
{
public:
	Player(const string name, const string description);
	~Player();

	void Do(const string word1, const string word2);

	Room* currentRoom;
	int itemsEquiped;

private:
	returnsType getItem(const string item, Entity* owner);
	void Look(const string item);
	void Go(const string direction);
	void Open(const string item);
	void Take(const string item);
	void Leave(const string item);
	void Equip(const string item);

	DirectionType directionWatching;
	const int maxItemsEquiped = 2;
};