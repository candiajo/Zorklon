#include "stdafx.h"
#include "world.h"
#include "room.h"
#include "item.h"
#include "player.h"
#include "door.h"
#include <iostream>

#include <list>

World::World()
{
	// Rooms
	Room* mainHall = new Room("Main Hall", "You are in room with four doors.");
		
	Room* cryptGarden = new Room("Crypt Garden", "You are in the garden before the crypt entrance.");
	Item* venom = new Item("venom", "A little bottle with venom.");
	Item* venom2 = new Item("venom2", "2A little bottle with venom.");
	Item* venom3 = new Item("venom3", "3A little bottle with venom.");
	Item* bag = new Item("bag", "A bag.");
	mainHall->AddItem(venom);
	mainHall->AddItem(venom2);
	mainHall->AddItem(venom3);
	mainHall->AddItem(bag);

	Door* doorMainHall_CryptGarden = new Door(EAST, WEST, mainHall, cryptGarden);

	rooms.push_back(mainHall);
	rooms.push_back(cryptGarden);


	// Player
	player = new Player("Hero", "You are a very handsome guy.");
	player->currentRoom = mainHall;
	
};

World::~World()
{

}

