#pragma once
#include <vector>
#include "Products.h"

class Player
{
public:
	Player() = default;
	float money = 0.f;
	std::vector<int/*Items*/> inventory;
	Products::Product* stage = nullptr;
	void LoadPlayer();
};

