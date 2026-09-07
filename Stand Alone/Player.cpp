#include "Player.h"
#include <cstring>
#include <fstream>

void Player::LoadPlayer() {
	std::ifstream f("Save.txt");
	char* save_file = new char[1024];
	char* context = nullptr;
	char* token = nullptr;
	while (f >> save_file) {
		token = strtok_s(save_file, ":", &context);
		if (strcmp(token, "Money") == 0) {
			token = strtok_s(nullptr, ":", &context);
			this->money = atof(isdigit(token[0]) ? token : "0");
		}
		else if (strcmp(token, "Inventory") == 0) {
		}
		else if (strcmp(token, "Stage") == 0) {
		}
		else if (strcmp(token, "PriceUpgrade") == 0) {

		}
		else if (strcmp(token, "QualityUpgrade") == 0) {
		}
		else if (strcmp(token, "StorageUpgrade") == 0) {
		}
		else if (strcmp(token, "MainCharacter") == 0) {
		}
	}
}
