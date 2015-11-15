#pragma once

#include "room.h"
#include "player.h"
#include <list>


class World
{
private:
	list<Room*> rooms;

public:
	World();
	~World();

	Player* player;
};