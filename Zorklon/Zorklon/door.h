#pragma once

#include "entity.h"
#include <string>
#include <array>

using namespace std;

class Room;

class Door : public Entity
{
public:
	Door(const DirectionType inDirectionA, const DirectionType inDirectionB, Room* sideA, Room* sideB);
	~Door();
	Room* getNextRoom(Room* previousRoom);
	bool doorIsLocked();
	void checkDoor();	// tells the color of the keys needed for opening the door
	void setDoorLock(const int redLock, const int blueLock, const int greenLock);

	Room* sideA;
	Room* sideB;
	array<int, MAX_DOORLOCKS> doorlock;

	bool isOpen = false;
};