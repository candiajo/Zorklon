#pragma once

#include "room.h"
#include "player.h"
#include <list>


class World
{
public:
	World();
	~World();

	Player* player;
};