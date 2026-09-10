#pragma once
#include "Items.h"
class Entities
{
	Entities();
	unsigned short x, y;
	bool hasItem = false;
	Items::Item* item = nullptr;
	Entities* next_Entity = nullptr;
	void SetNextEntity(Entities* next);
};

