#pragma once

enum DirectionType
{
	NOWHERE = -1,
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum colorType
{
	RED,
	BLUE,
	GREEN
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
