#include "stdafx.h"
#include "world.h"
#include "room.h"
#include "item.h"
#include "player.h"
#include "door.h"
#include "types.h"
#include "enemy.h"

#include <list>

using namespace std;

World::World()
{
	// Rooms

	Room* mainHall = new Room("Main Hall", "You are in the hall of the mansion, a room with four doors.");
	Room* graveyardGarden = new Room("Graveyard Garden", "A garden with beautiful flowers but a bit sad to stay.");
	Room* graveyardEntrance = new Room("Graveyard Entrance", "A place surrounded by fences, to the west you can see the Graveyard.");
	Room* graveyard = new Room("Graveyard", "You are in the graveyard of the family.");
	Room* chapelEntrance = new Room("Chapel Entrance", "A beautiful chamber with large pictures on the walls.");
	Room* chapel = new Room("Chapel", "This is a little room with saints and figures.");
	Room* cryptGarden = new Room("Crypt Garden", "The garden that leads to the crypt is dark an abandoned.");
	Room* cryptEntrance = new Room("Crypt Entrance", "You are in a narrow room with low ceiling.");
	Room* crypt = new Room("Crypt", "A humid place, with water on the floor. It seems that a big creature lived here.");
	Room* frontYard = new Room("Front Yard", "You are in a big area outside the house, surrounded by a small fence.");
	
	entities.push_back(mainHall);
	entities.push_back(graveyardGarden);
	entities.push_back(graveyardEntrance);
	entities.push_back(graveyard);
	entities.push_back(chapelEntrance);
	entities.push_back(chapel);
	entities.push_back(cryptGarden);
	entities.push_back(cryptEntrance);
	entities.push_back(crypt);
	entities.push_back(frontYard);

	// Items
	Item* poison = new Item("poison", "A little bottle with POISON. You can POISON things with it.", 15);
	Item* tool1 = new Item("tool", "A TOOL. You can UPGRADE the sword or the shield (one use).", 5);
	Item* tool2 = new Item("tool", "A TOOL. You can UPGRADE the sword or the shield (one use).", 5);
	Item* tool3 = new Item("tool", "A TOOL. You can UPGRADE the sword or the shield (one use).", 5);
	Item* sword = new Item("sword", "A big, fancy SWORD. You can use it to ATTACK with more power.", 10);
	Item* shield = new Item("shield", "A wood SHIELD, doesn't seem very solid.", 5);
	Item* bag = new Item("bag", "A BAG, you can STORE infinite items inside, and you can EQUIP them.");
	Item* redKey = new Item("redkey", "A rusty old red key (I'll call it REDKEY), you can OPEN doors with red locks.");
	Item* blueKey = new Item("bluekey", "A little strange blue key (I'll call it BLUEKEY), you can OPEN doors with blue locks.");	
	Item* meat = new Item("meat", "A piece of rotten MEAT. Maybe some monster will eat this if I LEAVE it in the ground.");

	cryptGarden->addItem(poison);
	crypt->addItem(redKey);
	chapel->addItem(blueKey);
	cryptEntrance->addItem(tool1);
	chapelEntrance->addItem(tool2);
	graveyardEntrance->addItem(tool3);
	graveyard->addItem(meat);
	crypt->addItem(sword);
	chapel->addItem(shield);
	crypt->addItem(bag);

	// Doors
	Door* door_MainHall_CryptGarden = new Door(EAST, WEST, mainHall, cryptGarden);
	Door* door_CryptGarden_CryptEntrance = new Door(SOUTH, NORTH, cryptGarden, cryptEntrance);
	Door* door_CryptEntrance_ChapelEntrance = new Door(WEST, EAST, cryptEntrance, chapelEntrance);
	door_CryptEntrance_ChapelEntrance->setDoorLock(UNLOCKED, LOCKED, UNLOCKED);
	Door* door_CryptEntrance_Crypt = new Door(SOUTH, NORTH, cryptEntrance, crypt);
	Door* door_Crypt_Chapel = new Door(WEST, EAST, crypt, chapel);
	door_Crypt_Chapel->setDoorLock(UNLOCKED, LOCKED, UNLOCKED);
	Door* door_MainHall_ChapelEntrance = new Door(SOUTH, NORTH, mainHall, chapelEntrance);
	door_MainHall_ChapelEntrance->setDoorLock(LOCKED, UNLOCKED, UNLOCKED);
	Door* door_ChapelEntrance_GraveyardEntrance = new Door(WEST, EAST, chapelEntrance, graveyardEntrance);
	door_ChapelEntrance_GraveyardEntrance->setDoorLock(UNLOCKED, UNLOCKED, LOCKED);
	Door* door_ChapelEntrance_Chapel = new Door(SOUTH, NORTH, chapelEntrance, chapel);
	Door* door_MainHall_GraveyardGarden = new Door(WEST, EAST, mainHall, graveyardGarden);
	door_MainHall_GraveyardGarden->setDoorLock(UNLOCKED, LOCKED, UNLOCKED);
	Door* door_GraveyardGarden_GraveyardEntrance = new Door(SOUTH, NORTH, graveyardGarden, graveyardEntrance);
	Door* door_GraveyardEntrance_Graveyard = new Door(WEST, EAST, graveyardEntrance, graveyard);
	Door* door_MainHall_Frontyard = new Door(NORTH, SOUTH, mainHall, frontYard);
	door_MainHall_Frontyard->setDoorLock(LOCKED, LOCKED, LOCKED);

	entities.push_back(door_MainHall_CryptGarden);
	entities.push_back(door_CryptGarden_CryptEntrance);
	entities.push_back(door_CryptEntrance_ChapelEntrance);
	entities.push_back(door_CryptEntrance_Crypt);
	entities.push_back(door_Crypt_Chapel);
	entities.push_back(door_MainHall_ChapelEntrance);
	entities.push_back(door_ChapelEntrance_GraveyardEntrance);
	entities.push_back(door_ChapelEntrance_Chapel);
	entities.push_back(door_MainHall_GraveyardGarden);
	entities.push_back(door_GraveyardGarden_GraveyardEntrance);
	entities.push_back(door_GraveyardEntrance_Graveyard);
	entities.push_back(door_MainHall_Frontyard);

	// Enemies
	Enemy* goblin1 = new Enemy("goblin1", "An ugly creature, a GOBLIN, is in the middle of the room. Be careful.", 15, 2, 40);
	Enemy* goblin2 = new Enemy("goblin2", "A strange creature, it's a GOBLIN. Looks unfriendly.", 18, 2, 40);
	Enemy* goblin3 = new Enemy("goblin3", "A big GOBLIN in a hole in the wall, it's hidden and protected from your attacks.", 11, 999, 70);
	Enemy* boss = new Enemy("boss", "A huge MONSTER in front of you, it's hungry...", 30, 10, 60);

	chapelEntrance->setEnemy(goblin1);
	graveyardGarden->setEnemy(goblin2);
	crypt->setEnemy(goblin3);
	frontYard->setEnemy(boss);
	
	// Player
	player = new Player("Hero", "You are a very handsome guy.", 10, 10, 90);
	player->currentRoom = mainHall;

	entities.push_back(player);
};

World::~World()
{
	for (auto& entity : entities) delete(entity);
	entities.clear();
}

