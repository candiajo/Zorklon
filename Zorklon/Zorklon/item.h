#pragma once

#include "entity.h";

class Item : public Entity
{
public:
	Item(const char* name, const char* description);
	Item(const char* name, const char* description, const int usePoints);
	~Item();

	int usePoints;	// points for upgrading attack, defense, and other stuff...
};