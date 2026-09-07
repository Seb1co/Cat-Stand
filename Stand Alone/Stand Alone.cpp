#include <fstream>
#include <iostream>
#include <cstring>
#include "Settings.h"
#include "Player.h"

std::ifstream f("Settings.txt");
int main()
{	
	SNS::Settings settings;
	settings.LoadSettings();
	Player player;
	player.LoadPlayer();
	
	
}

