#include "stdafx.h"
#include "player.h"
#include "entity.h"
#include "door.h"
#include "enemy.h"


class Item;

Player::Player(const string name, const string description) :
Entity(name, description)
{
	directionWatching = NOWHERE;
	attackPoints = 10;
	defensePoints = 10;
	lifePoints = 50;
};

void Player::Do(const string word1, const string word2)
{
	if (word1 == "look") Look(word2);
	else if (word1 == "go") Go(word2); else if (word1 == "go") Go(word2);
	else if (word1 == "open") Open(word2);
	else if (word1 == "take") Take(word2);
	else if (word1 == "leave") Leave(word2);
	else if (word1 == "equip") Equip(word2);
	else if (word1 == "store") Store(word2);
	else if (word1 == "attack") Attack(word2);
	else if (word1 == "upgrade") Upgrade(word2);
	else if (word1 == "poison") Poison(word2);
	else cout << "I don't understand this.\n";
}

bool Player::isDead()
{
	return (lifePoints <= 0);
}

int Player::itemsEquiped()
{
	int itemsEquiped = items.size();
	if (dynamic_cast<Item*>(findByName("bag")) != NULL) --itemsEquiped; // bag doesn't count as an item equiped
	return itemsEquiped;
}

returnsType Player::getItem(const string item, Entity* owner)
{
	Item* foundItem;

	// search the item in the owner's list
	foundItem = dynamic_cast<Item*>(owner->extractItem(item));

	if (foundItem != NULL)
	{
		if (itemsEquiped() == maxItemsEquiped)
		{
			owner->addItem(foundItem);
			return TOO_MANY;
		}
		else
		{
			addItem(foundItem);
			return ITEM_GOT;
		}
	}
	else
		return NOT_FOUND;
}

returnsType Player::putItem(const string item, Entity* newOwner)
{
	Item* foundItem;

	// search the item in the player's list (items equiped)
	foundItem = dynamic_cast<Item*>(extractItem(item));

	if (foundItem == NULL)
		return NOT_FOUND;
		//cout << "You don't have that item.\n";
	else
	{
		newOwner->addItem(foundItem);
		return ITEM_PUT;
	}
}

void Player::clearEnemy(Room* enemyRoom)
{
	cout << "The enemy has been killed.\n";
	delete(enemyRoom->enemy);
	enemyRoom->enemy = NULL;
}

void Player::exitRoom()
{
	if (currentRoom->enemy != NULL)
	{
		currentRoom->enemy->attackPlayer(this);
	}
	if (!isDead())
	{
		currentRoom = currentRoom->door[directionWatching]->getNextRoom(currentRoom);
		cout << currentRoom->description << "\n";
		directionWatching = NOWHERE;
	}
}

void Player::receiveAttack(int enemyAttackPoints)
{
	int enemyLifeBefore = lifePoints;
	int totalDefensePoints = defensePoints;
	Item* shield = dynamic_cast<Item*>(findByName("shield"));

	if (shield != NULL)	totalDefensePoints += shield->usePoints;		// if the player has a shield, increases his defense power
	
	enemyAttackPoints -= totalDefensePoints;
	if (enemyAttackPoints < 0) enemyAttackPoints = 0;

	lifePoints = lifePoints - enemyAttackPoints;

	cout << "The enemy in the room attack you before you exit.\n";
	cout << "The attack caused " << enemyLifeBefore - lifePoints << " points of damage.\n";

	if (lifePoints <= 0)
	{
		cout << "The hero has fallen...\n";
	}
	else
	{
		cout << "You have " << lifePoints << " points of life now.\n";
	}
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
	else if (direction == "") cout << "You have to tell what direction to go (north, south, east, west).\n";
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
			exitRoom();
		}
		else																	// the door is closed
		{
			cout << "The door in front of you is closed.\n";
			currentRoom->door[directionWatching]->checkDoor();
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
			Door* door = currentRoom->door[directionWatching];

			if (door->doorlock[RED] == LOCKED)
			{
				cout << "This door is locked by a RED LOCK.\n";
				if (dynamic_cast<Item*>(findByName("redkey")) != NULL)
				{
					door->doorlock[RED] = UNLOCKED;
					cout << "- You used the RED KEY and unlocked it.\n";
				}
			}

			if (door->doorlock[GREEN] == LOCKED)
			{
				cout << "This door is locked by a GREEN LOCK.\n";
				if (dynamic_cast<Item*>(findByName("greenkey")) != NULL)
				{
					door->doorlock[GREEN] = UNLOCKED;
					cout << "- You used the GREEN KEY and unlocked it.\n";
				}
			}

			if (door->doorlock[BLUE] == LOCKED)
			{
				cout << "This door is locked by a BLUE LOCK.\n";
				if (dynamic_cast<Item*>(findByName("bluekey")) != NULL)
				{
					door->doorlock[BLUE] = UNLOCKED;
					cout << "- You used the BLUE KEY and unlocked it.\n";
				}
			}

			if (!currentRoom->door[directionWatching]->doorIsLocked()) Open("door");
		}
		else
		{
			cout << "You opened the door and go ahead.\n";
			currentRoom->door[directionWatching]->isOpen = true;
			exitRoom();
		}
	}
	else
		cout << "You can't open that.\n";
}

void Player::Take(const string item)
{
	returnsType response = getItem(item, currentRoom);

	if (item == "") 
		cout << "You have to tell what to take.\n";
	else
	{
		if (response == ITEM_GOT)
			cout << "You've taken the " << item << ".\n";
		else if (response == NOT_FOUND)
			cout << "There is not such item near.\n";
		else if (response == TOO_MANY)
			cout << "You have too many items equiped, leave one or store one if you have a BAG.\n";
	}
}

void Player::Leave(const string item)
{
	if (item == "")
		cout << "You have to tell what to leave.\n";
	else
	{
		if (putItem(item, currentRoom) == ITEM_PUT)
			cout << "You left the " << item << ".\n";
		else
			cout << "You don't have that item.\n";
	}
}

void Player::Equip(const string item)
{
	Item* bag = dynamic_cast<Item*>(findByName("bag"));
	returnsType response;

	if (item == "")
		cout << "You have to tell what to equip.\n";
	else
	{
		if (item == "bag")
			cout << "You can't equip that.\n";
		else if (bag == NULL)											// player don't have a bag
			cout << "You don't have a BAG with items to equip.\n";
		else if (dynamic_cast<Item*>(findByName(item)) != NULL)			// the player is trying to equip an item already equiped
			cout << "You have " << item << " already equiped.\n";
		else
		{
			response = getItem(item, bag);

			if (response == ITEM_GOT)								// the item is in the bag and the player has space to equip
				cout << "You've equiped the " << item << ".\n";
			else if (response == NOT_FOUND)								// the item is not in the bag
				cout << "You don't have that item in your bag.\n";
			else if (response == TOO_MANY)								// the player has too many objects equiped
				cout << "You have too many items equiped, leave one or store one if you have a BAG.\n";
		}
	}
}

void Player::Store(const string item)
{
	Item* bag = dynamic_cast<Item*>(findByName("bag"));

	if (item == "")
		cout << "You have to tell what to store.\n";
	else
	{
		if (item == "bag")
			cout << "You can't store that.\n";
		else if (bag == NULL)										// the player don't have a bag
			cout << "You need a BAG for storing items.\n";
		else if (putItem(item, bag) == ITEM_PUT)					// item stored in the bag
			cout << "You stored the " << item << " in the bag.\n";
		else														// the player don't have that item
			cout << "You don't have that item.\n";
	}
}

void Player::Attack(const string item)
{
	int totalAttackPoints = attackPoints;
	Item* sword;
	int enemyLifeAfter;
	int enemyLifeBefore;

	if (item == "") cout << "You must tell what to attack.\n";
	else if ((item == "goblin" || item == "monster" || item == "enemy") && currentRoom->enemy != NULL)
	{
		sword = dynamic_cast<Item*>(findByName("sword"));
		if (sword != NULL)  
		{
			cout << "You attack the enemy with your sword.\n";
			totalAttackPoints += sword->usePoints;		// if the player has a sword, increases his attack power
		}
		else
		{
			cout << "You attack the enemy with your hands.\n";
		}
		
		enemyLifeBefore = currentRoom->enemy->lifePoints;
		enemyLifeAfter = currentRoom->enemy->receiveAttack(totalAttackPoints);
		if (enemyLifeAfter <= 0) 
			clearEnemy(currentRoom);
		else
		{
			cout << "Your attack caused " << enemyLifeBefore - enemyLifeAfter << " points of damage.\n";
			cout << "The enemy has " << enemyLifeAfter << " points of life now.\n";
		}
	}
	else
		cout << "There is no " << item << " in this room.\n";
}

void Player::Upgrade(const string item)
{
	Item* upgradeTool = dynamic_cast<Item*>(findByName("tool"));
	Item* itemToUpgrade;

	if (item == "") 
		cout << "You must tell what to upgrade.\n";
	else if (upgradeTool == NULL)
		cout << "You must have an upgrade tool equiped.\n";
	else if (item != "sword" && item != "shield")
		cout << "You cannot upgrade that.\n";
	else 
	{
		itemToUpgrade = dynamic_cast<Item*>(findByName(item));
		if (itemToUpgrade == NULL) 
			cout << "You must have the " << item << " equiped in order to upgrade it.\n";
		else
		{
			upgradeTool = dynamic_cast<Item*>(extractItem("tool"));
			cout << "Your " << item << " upgrades from " << itemToUpgrade->usePoints;
			itemToUpgrade->usePoints += upgradeTool->usePoints;
			cout << " to " << itemToUpgrade->usePoints << " points.\n";
			delete(upgradeTool);
		}
	}
}

void Player::Poison(const string item)
{
	Item* poisonBottle = dynamic_cast<Item*>(findByName("poison"));
	Item* itemToPoison;

	if (item == "")
		cout << "You must tell what to poison.\n";
	else if (poisonBottle == NULL)
		cout << "You must have a bottle of poison equiped.\n";
	else if (item != "sword" && item != "meat")
		cout << "You cannot poison that.\n";
	else
	{
		itemToPoison = dynamic_cast<Item*>(findByName(item));
		if (itemToPoison == NULL)
			cout << "You must have the " << item << " equiped in order to poison it.\n";
		else
		{
			poisonBottle = dynamic_cast<Item*>(extractItem("poison"));
			cout << "Your " << item << " upgrades from " << itemToPoison->usePoints;
			itemToPoison->usePoints += poisonBottle->usePoints;
			cout << " to " << itemToPoison->usePoints << " points of damage.\n";
			delete(poisonBottle);
		}
	}
	cout << itemsEquiped();
}

Player::~Player()
{};