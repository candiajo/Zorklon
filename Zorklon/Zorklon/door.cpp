#include "stdafx.h"
#include "door.h"
#include "room.h"

Door::Door(const DirectionType inDirectionA, const DirectionType inDirectionB, Room* sideA, Room* sideB)
{
	this->sideA = sideA;
	this->sideB = sideB;

	sideA->door[inDirectionA] = this;
	sideB->door[inDirectionB] = this;
	
	doorlock.fill(UNLOCKED);
}

Room* Door::getNextRoom(const Room* previousRoom) const
{
	if (sideA == previousRoom)
		return sideB;
	else
		return sideA;
}

bool Door::doorIsLocked() const
{
	int locks = 0;

	for (int lockStatus : doorlock)
	{
		locks += lockStatus;
	}

	return (locks > 0);
}

void Door::checkDoor() const
{
	if (doorlock[RED] + doorlock[BLUE] + doorlock[GREEN] == 0) cout << "The door hasn't any locks.\n";
	else
	{
		if (doorlock[RED] == 1)  cout << "You need the RED key for this door.\n";
		if (doorlock[BLUE] == 1)  cout << "You need the BLUE key for this door.\n";
		if (doorlock[GREEN] == 1)  cout << "You need the GREEN key for this door.\n";
	}
}

void Door::setDoorLock(const int redLock, const int blueLock, const int greenLock)
{
	doorlock[RED] = redLock;
	doorlock[BLUE] = blueLock;
	doorlock[GREEN] = greenLock;
}

Door::~Door()
{}