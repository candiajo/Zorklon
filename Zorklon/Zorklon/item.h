#pragma once

#include "entity.h";

class Item : public Entity
{
public:
	Item(const string name, const string description);
	Item(const string name, const string description, const int usePoints);
	~Item();

	int usePoints;	// points for upgrading attack, defense, and other stuff...
};