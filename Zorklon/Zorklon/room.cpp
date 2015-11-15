#include "stdafx.h"
#include "room.h"
#include "door.h"
#include <iostream>

Room::Room(const string name, const string description) :
Entity(name, description)
{
	door.fill(NULL);
};


Room* Room::getRoom(DirectionType direction)
{
	return door[direction]->getNextRoom(this);
};

Room::~Room()
{};