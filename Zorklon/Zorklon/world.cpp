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
	Room* mainHall = new Room("Main Hall", "You are in room with four doors.");
		
	Room* cryptGarden = new Room("Crypt Garden", "You are in the garden before the crypt entrance.");
	Item* venom = new Item("venom", "A little bottle with venom.", 15);
	Item* bag = new Item("bag", "A bag.");
	Item* redKey = new Item("redkey", "A red key.");
	Item* greenKey = new Item("greenkey", "A green key.");
	Item* blueKey = new Item("bluekey", "A blue key.");
	Item* sword = new Item("sword", "A big sword.", 10);
	Item* shield = new Item("shield", "A wood shield.", 5);
	Item* upgrade1 = new Item("upgrade1", "An upgrade for the sword or the shield.", 5);
	Item* upgrade2 = new Item("upgrade2", "An upgrade for the sword or the shield.", 5);
	Item* upgrade3 = new Item("upgrade3", "An upgrade for the sword or the shield.", 5);
	Item* meat = new Item("meat", "A piece of rotten meat.");
	Enemy* greenGoblin = new Enemy("greenGoblin", "A little green goblin.", 11, 2, 40);

	mainHall->setEnemy(greenGoblin);

	mainHall->addItem(upgrade1);
	mainHall->addItem(upgrade2);
	mainHall->addItem(upgrade3);
	mainHall->addItem(meat);
	mainHall->addItem(sword);
	mainHall->addItem(redKey);
	mainHall->addItem(greenKey);
	mainHall->addItem(blueKey);
	mainHall->addItem(venom);
	mainHall->addItem(bag);

	Door* doorMainHall_CryptGarden = new Door(EAST, WEST, mainHall, cryptGarden);
	//doorMainHall_CryptGarden->setDoorLock(LOCKED, LOCKED, LOCKED);
	rooms.push_back(mainHall);
	rooms.push_back(cryptGarden);


	// Player
	player = new Player("Hero", "You are a very handsome guy.");
	player->currentRoom = mainHall;
	
};

World::~World()
{

}

