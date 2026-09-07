#include <fstream>
#include <iostream>
#include <cstring>
#include "Settings.h"

std::ifstream f("Settings.txt");
int main()
{	
	SNS::Settings settings;
	settings.LoadSettingss();
	
	
}

