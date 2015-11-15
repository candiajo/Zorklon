#pragma once

#include <string>
#include <list>
#include "types.h"

using namespace std;

class Entity
{
public:
	string name;
	string description;

public:
	Entity();
	Entity(const string name, const string description);
	virtual ~Entity();
};	