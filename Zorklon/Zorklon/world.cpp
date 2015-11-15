#include "stdafx.h"
#include "world.h"
#include "room.h"
#include "item.h"
#include "player.h"
#include "door.h"
#include "enemy.h"

#include <list>

World::World()
{
	// Rooms
	Room* mainHall = new Room("Main Hall", "You are in the hall of the mansion, a room with four doors.");
	Room* graveyardGarden = new Room("Graveyard Garden", "A garden with beautiful flowers but a bit sad to stay.");
	Room* graveyardEntrance = new Room("Graveyard Entrance", "A place surrounded by fences, to the west you can see the Graveyard.");
	Room* graveyard = new Room("Graveyard", "You are in the graveyard of the family.");
	Room* chapelEntrance = new Room("Chapel Entrance", "A beautiful chamber with large pictures on the walls.");
	Room* Chapel = new Room("Chapel", "This is a little room with saints and figures.");
	Room* cryptGarden = new Room("Crypt Garden", "The garden that leads to the crypt is dark an abandoned.");
	Room* cryptEntrance = new Room("Crypt Entrance", "You are in a narrow room with low ceiling.");
	Room* crypt = new Room("Crypt", "A humid place, with water on the floor. It seems that a big creature lived here.");
	Room* frontYard = new Room("Front Yard", "You are in a big area outside the house, surrounded by a small fence.");
	
	/*
	// Rooms
	
	Item* poison = new Item("poison", "A little bottle with poison.", 15);
	Item* poison2 = new Item("poison", "A little bottle with poison.", 15);
	Item* poison3 = new Item("poison", "A little bottle with poison.", 15);
	Item* bag = new Item("bag", "A bag.");
	Item* redKey = new Item("redkey", "A red key.");
	Item* greenKey = new Item("greenkey", "A green key.");
	Item* blueKey = new Item("bluekey", "A blue key.");
	Item* sword = new Item("sword", "A big sword.", 10);
	Item* shield = new Item("shield", "A wood shield.", 5);
	Item* tool1 = new Item("tool", "A tool for upgrading the sword or the shield.", 5);
	Item* tool2 = new Item("tool", "A tool for upgrading the sword or the shield.", 5);
	Item* tool3 = new Item("tool", "A tool for upgrading the sword or the shield.", 5);
	Item* meat = new Item("meat", "A piece of rotten meat.");
	Enemy* greenGoblin = new Enemy("greenGoblin", "A little green goblin.", 11, 2, 40);

	mainHall->setEnemy(greenGoblin);

	mainHall->addItem(tool1);
	mainHall->addItem(tool2);
	mainHall->addItem(tool3);
	mainHall->addItem(meat);
	mainHall->addItem(sword);
	mainHall->addItem(shield);
	mainHall->addItem(redKey);
	mainHall->addItem(greenKey);
	mainHall->addItem(blueKey);
	mainHall->addItem(poison);
	mainHall->addItem(poison2);
	mainHall->addItem(poison3);
	mainHall->addItem(bag);

	Door* doorMainHall_CryptGarden = new Door(EAST, WEST, mainHall, cryptGarden);
	//doorMainHall_CryptGarden->setDoorLock(LOCKED, LOCKED, LOCKED);
	rooms.push_back(mainHall);
	rooms.push_back(cryptGarden);
	*/

	// Player
	player = new Player("Hero", "You are a very handsome guy.");
	player->currentRoom = mainHall;
	
};

World::~World()
{

}

