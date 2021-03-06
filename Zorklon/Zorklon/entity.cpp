#include "stdafx.h"

#include "entity.h"


Entity::Entity()
{}

Entity::Entity(const char* name, const char* description) :
	name(name), description(description)
{}

// returns the item and removes it from the list
Entity* Entity::extractItem(const string name)
{
	for (list<Entity*>::const_iterator it = items.cbegin(); it != items.cend(); ++it)
	{
		if ((*it)->name == name)
		{
			Entity* item = *it;
			items.erase(it);
			return item;
		}
	}

	return NULL;
}

// returns the item from the list
Entity* Entity::findByName(const string name) const
{
	for (list<Entity*>::const_iterator it = items.cbegin(); it != items.cend(); ++it)
	{
		if ((*it)->name == name)
			return *it;
	}

	return NULL;
}

void Entity::addItem(Entity* item)
{
	items.push_back(item);
};

Entity::~Entity()
{}