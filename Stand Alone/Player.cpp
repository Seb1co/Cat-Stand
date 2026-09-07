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
			token = strtok_s(nullptr, ",", &context);
			while (token != NULL) {
				this->inventory.push_back(atoi(isdigit(token[0]) ? token : "0"));
				token = strtok_s(nullptr, ",", &context);
			}
		}
		else if (strcmp(token, "Stage") == 0) {
			token = strtok_s(nullptr, ":", &context);
			if (isdigit(token[0])) {
				int stageType = atoi(token);
				switch (stageType) {
				case 0:
					this->stage = new Products::Lemonade();
					break;
				case 1:
					this->stage = new Products::Coffee();
					break;
				case 2:
					this->stage = new Products::Boba();
					break;
				default:
					this->stage = new Products::Lemonade();
					break;
				}
			}
			else {
				this->stage = new Products::Lemonade();
			}
		
		}
		else if (strcmp(token, "PriceUpgrade") == 0) {
			token = strtok_s(nullptr, ":", &context);
			this->stage->IncreaseUpgrade(2,atoi(isdigit(token[0]) ? token : "1"));
		}
		else if (strcmp(token, "QualityUpgrade") == 0) {
			token = strtok_s(nullptr, ":", &context);
			this->stage->IncreaseUpgrade(0, atoi(isdigit(token[0]) ? token : "1"));
		}
		else if (strcmp(token, "StorageUpgrade") == 0) {
			token = strtok_s(nullptr, ":", &context);
			this->stage->IncreaseUpgrade(1, atoi(isdigit(token[0]) ? token : "1"));
		}
		else if (strcmp(token, "MainCharacter") == 0) {
		
		}
	}
}
