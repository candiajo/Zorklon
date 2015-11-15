#pragma once

#include "stdafx.h"
#include "player.h"
#include "entity.h"
#include "door.h"
#include <iostream>

Player::Player(const string name, const string description) :
Entity(name, description)
{};

void Player::Do(const string word1, const string word2)
{
	if (word1 == "look") Look(word2);
	else if (word1 == "go") Go(word2); else if (word1 == "go") Go(word2);
	else if (word1 == "open") Open(word2);

}

void Player::Look(const string item)
{
	if (item == "")
		cout << currentRoom->description << "\n";
}

void Player::Go(const string direction)
{
	if		(direction == "north") directionWatching = NORTH;
	else if (direction == "south") directionWatching = SOUTH;
	else if (direction == "east") directionWatching = EAST;
	else if (direction == "west") directionWatching = WEST;
	else cout << "Can't recognize that direction.\n";

	if (directionWatching != NOWHERE)
	{
		if (currentRoom->door[directionWatching] == NULL)						// there is a wall or any obstacle
		{
			cout << "You can't go in that direction.\n";
			directionWatching = NOWHERE;
		}
		else if (currentRoom->door[directionWatching]->isOpen)				// the door is open
		{
			currentRoom = currentRoom->door[directionWatching]->getNextRoom(currentRoom);
			cout << currentRoom->description;
			directionWatching = NOWHERE;
		}
		else																	// the door is closed
		{
			cout << "The door in front of you is closed.\n";
			// e informar del color de la cerradura
		}
	}
};

void Player::Open(const string item)
{
	if (item == "door")
	{
		if (directionWatching == NOWHERE) cout << "You don't have a door in front of you.\n";
		else if (currentRoom->door[directionWatching]->doorIsLocked())
		{
			cout << "The door is locked. You have to use a key to open it.\n";
			currentRoom->door[directionWatching]->checkDoor();
		}
		else
		{
			cout << "You opened the door and go ahead.\n";
			currentRoom->door[directionWatching]->isOpen = true;
		}
	}
}

Player::~Player()
{};