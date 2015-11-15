#include "stdafx.h"
#include "player.h"
#include "entity.h"
#include "door.h"
#include <iostream>

class Item;

Player::Player(const string name, const string description) :
Entity(name, description)
{
	itemsEquiped = 0;
	directionWatching = NOWHERE;
};

void Player::Do(const string word1, const string word2)
{
	if (word1 == "look") Look(word2);
	else if (word1 == "go") Go(word2); else if (word1 == "go") Go(word2);
	else if (word1 == "open") Open(word2);
	else if (word1 == "take") Take(word2);
	else if (word1 == "leave") Leave(word2);
	else if (word1 == "equip") Equip(word2);
	else cout << "I don't understand this.\n";
}

returnsType Player::getItem(const string item, Entity* owner)
{
	Item* foundItem;

	// search the item in the owner's list
	foundItem = dynamic_cast<Item*>(owner->extractItem(item));

	if (foundItem != NULL)
	{
		// the BAG doesn't count as an equiped item
		if (itemsEquiped == maxItemsEquiped && item != "bag")
		{
			cout << "You have too many items equiped, leave one or store one if you have a BAG.\n";
			owner->AddItem(foundItem);
			return TOO_MANY;
		}
		else
		{
			AddItem(foundItem);
			if (item != "bag") ++itemsEquiped;
			return GOT_ITEM;
		}
	}
	else
		return NOT_FOUND;
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
		else if (currentRoom->door[directionWatching]->isOpen)					// the door is open
		{
			currentRoom = currentRoom->door[directionWatching]->getNextRoom(currentRoom);
			cout << currentRoom->description << "\n";
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
			currentRoom = currentRoom->door[directionWatching]->getNextRoom(currentRoom);
			cout << currentRoom->description << "\n";
			directionWatching = NOWHERE;
		}
	}
}

void Player::Take(const string item)
{
	returnsType response = getItem(item, currentRoom);

	if (response == GOT_ITEM)
		cout << "You've taken the " << item << ".\n";
	else if (response == NOT_FOUND)
		cout << "There is not such item near.\n";
	else if (response == TOO_MANY)
		{/*already said*/}
}

void Player::Leave(const string item)
{
	Item* foundItem;

	// search the item in the player's list
	foundItem = dynamic_cast<Item*>(extractItem(item));

	if (foundItem == NULL)
		cout << "You don't have that item.\n";
	else
	{
		currentRoom->AddItem(foundItem);
		if (item != "bag") --itemsEquiped;			// the BAG doesn't count as an equiped item
		cout << "You left the " << item << ".\n";
	}
}

void Player::Equip(const string item)
{
	Item* bag;
	returnsType response;
	
	bag = dynamic_cast<Item*>(findByName("bag"));
	
	if (bag == NULL)												// player don't have a bag
		cout << "You don't have a BAG with items to equip.\n";
	else
	{
		response = getItem(item, currentRoom);
		if (response == GOT_ITEM)									// the item is in the bag and the player has space to equip
			cout << "You've equiped the " << item << ".\n";
		else if (response == NOT_FOUND)								// the item is not in the bag
			cout << "You don't have that item in your bag.\n";
		else if (response == TOO_MANY)								// the player has too many objects equiped
			{/*already said*/}
	}
}

Player::~Player()
{};