#pragma once

#include "stdafx.h"

#include "entity.h"


Entity::Entity()
{}

Entity::Entity(const string name, const string description) :
	name(name), description(description)
{}

Entity::~Entity()
{}