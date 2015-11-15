#include "stdafx.h"
#include "room.h"
#include "door.h"
#include <iostream>

Room::Room(const string name, const string description) :
Entity(name, description)
{
	door.fill(NULL);
};

void Room::AddItem(Item* item)
{
	items.push_back(item);
};

Room* Room::getRoom(DirectionType direction)
{
	return door[direction]->getNextRoom(this);
};

Room::~Room()
{};