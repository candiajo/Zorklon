#pragma once

#include "stdafx.h"
#include "entity.h"
#include "item.h"
#include <list>;
#include <array>

using namespace std;


class Door;

class Room: public Entity
{
private:
	
	// lista de criaturas

public:
	array<Door*, 4> door;

public:
	Room(const string name, const string description);
	~Room();
	Room* getRoom(DirectionType direction);
};