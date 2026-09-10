#include "Items.h"
#include <cstring>
Items::PricePotion::PricePotion() {
	this->chanceWeight = 3;
	strcpy_s(this->name,12,"PricePotion");
}
Items::QualityPotion::QualityPotion() {
	this->chanceWeight = 10;
	strcpy_s(this->name, 14, "QualityPotion");
}
Items::StoragePotion::StoragePotion() {
	this->chanceWeight = 13;
	strcpy_s(this->name, 14, "StoragePotion");
}