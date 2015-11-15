#pragma once

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
	Room* mainHall = new Room("Main Hall", "A room with four doors.");
		
	Room* cryptGarden = new Room("Crypt Garden", "The garden before the crypt entrance.");
	Item* venom = new Item("Venom", "A little bottle with venom.");
	cryptGarden->AddItem(venom);

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

