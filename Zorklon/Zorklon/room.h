#pragma once

#include "stdafx.h"
#include "entity.h"
#include "item.h"
#include <list>;
#include <array>

using namespace std;

class Enemy;
class Door;

class Room: public Entity
{
public:
	array<Door*, 4> door;
	Enemy* enemy;

	Room(const char* name, const char* description);
	~Room();
	Room* getRoom(DirectionType direction);
	void setEnemy(Enemy* enemy);
};