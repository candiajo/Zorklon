#include "stdafx.h"
#include "room.h"
#include "door.h"

Room::Room(const char* name, const char* description) :
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
{
	for (auto& item : items) delete(item);
	if (enemy != NULL) delete(enemy);
	items.clear();
};