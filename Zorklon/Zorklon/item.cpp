#include "stdafx.h"
#include "item.h"

Item::Item(const string name, const string description) :
Entity(name, description)
{
	usePoints = 0;
};

Item::Item(const string name, const string description, const int usePoints) :
Entity(name, description)
{
	this->usePoints = usePoints;
}
Item::~Item()
{};