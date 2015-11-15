#include "stdafx.h"
#include "door.h"
#include "room.h"
#include <iostream>

Door::Door(const DirectionType inDirectionA, const DirectionType inDirectionB, Room* sideA, Room* sideB)
{
	this->sideA = sideA;
	this->sideB = sideB;

	sideA->door[inDirectionA] = this;
	sideB->door[inDirectionB] = this;
	
	doorlock.fill(UNLOCKED);
}


Room* Door::getNextRoom(Room* previousRoom)
{
	if (sideA == previousRoom)
		return sideB;
	else
		return sideA;
}

bool Door::doorIsLocked()
{
	int locks = 0;

	for (int lockStatus : doorlock)
	{
		locks += lockStatus;
	}

	return (locks > 0);
}

void Door::checkDoor()
{
	if (doorlock[RED] == 1)  cout << "You need the RED key for this door.\n";
	if (doorlock[BLUE] == 1)  cout << "You need the BLUE key for this door.\n";
	if (doorlock[GREEN] == 1)  cout << "You need the GREEN key for this door.\n";
}

void Door::setDoorLock(const int redLock, const int blueLock, const int greenLock)
{
	doorlock[RED] = redLock;
	doorlock[BLUE] = blueLock;
	doorlock[GREEN] = greenLock;
}

Door::~Door()
{}