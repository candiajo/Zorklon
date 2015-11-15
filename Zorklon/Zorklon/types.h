#pragma once

enum DirectionType
{
	NOWHERE = -1,
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

enum colorType
{
	RED = 0,
	BLUE = 1,
	GREEN = 2
};

enum returnsType
{
	ITEM_GOT,
	NOT_FOUND,
	TOO_MANY,
	ITEM_PUT
};

#define LOCKED 1
#define UNLOCKED 0

#define MAX_DOORLOCKS 3
