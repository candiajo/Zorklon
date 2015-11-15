#pragma once

#include "entity.h";

class Item : public Entity
{
public:
	Item(const string name, const string description);
	~Item();
};