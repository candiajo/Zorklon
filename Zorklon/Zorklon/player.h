#pragma once

#include "entity.h"
#include "room.h"

#include <string>

class Player : public Entity
{
public:
	Player(const string name, const string description);
	~Player();

	void Do(const string word1, const string word2);

	Room* currentRoom;

private:
	DirectionType directionWatching = NOWHERE;
	void Look(const string item);
	void Go(const string direction);
	void Open(const string item);
};