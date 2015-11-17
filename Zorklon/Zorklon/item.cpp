#include "stdafx.h"
#include "item.h"

Item::Item(const char* name, const char* description) :
Entity(name, description)
{
	usePoints = 0;
};

Item::Item(const char* name, const char* description, const int usePoints) :
Entity(name, description)
{
	this->usePoints = usePoints;
}
Item::~Item()
{
	for (auto& item : items) delete(item);
	items.clear();
};