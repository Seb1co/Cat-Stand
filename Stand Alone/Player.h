#pragma once
#include <vector>
#include "Products.h"

class Player
{
	Player() = default;
	float money;
	std::vector<int/*Items*/> inventory;
	Products::Product* stage;
	void LoadPlayer();
};

