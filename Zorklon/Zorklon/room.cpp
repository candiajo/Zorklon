#include "stdafx.h"
#include "room.h"
#include "door.h"

Room::Room(const string name, const string description) :
Entity(name, description)
{
	door.fill(NULL);
	enemy = NULL;
};

Room* Room::getRoom(DirectionType direction)
{
	return door[direction]->getNextRoom(this);
};

void Room::setEnemy(Enemy* enemy)
{
	this->enemy = enemy;
}

Room::~Room()
{};