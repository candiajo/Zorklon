#pragma once

#include <list>
#include "types.h"

using namespace std;

class Entity
{
public:
	Entity();
	Entity(const char* name, const char* description);
	virtual ~Entity();
	Entity* extractItem(const string name);
	Entity* findByName(const string name) const;
	void addItem(Entity* item);
	
	string name;
	string description;
	list<Entity*> items;
};	