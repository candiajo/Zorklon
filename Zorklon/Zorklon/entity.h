#pragma once

#include <string>
#include <list>
#include "types.h"

using namespace std;

class Entity
{
public:
	Entity();
	Entity(const string name, const string description);
	virtual ~Entity();
	Entity* extractItem(const string name);
	Entity* findByName(const string name);
	void AddItem(Entity* item);

	string name;
	string description;
	list<Entity*> items;
};	