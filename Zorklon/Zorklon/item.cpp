#pragma once

#include "stdafx.h"
#include "item.h"

Item::Item(const string name, const string description) :
Entity(name, description)
{

};

Item::~Item()
{};