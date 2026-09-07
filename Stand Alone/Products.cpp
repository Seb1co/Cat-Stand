#include "Products.h"
#include <cstring>

void Products::Product::IncreaseUpgrade(unsigned short upgradeType, unsigned short value) {
}

float Products::Product::GetMultiplier() {
	return 1.0f;
}

char* Products::Product::GetLogo() {
	return nullptr;
}


Products::Lemonade::Lemonade() {
	this->qualityUpgrade = 1;
	this->storageUpgrade = 1;
	this->priceUpgrade	 = 1;
}
Products::Lemonade::Lemonade(unsigned short qualityUpgrade, unsigned short storageUpgrade, unsigned short priceUpgrade, unsigned short productUpgrade) {
	this->qualityUpgrade = qualityUpgrade;
	this->storageUpgrade = storageUpgrade;
	this->priceUpgrade = priceUpgrade;
}

void Products::Lemonade::IncreaseUpgrade(unsigned short upgradeType, unsigned short value) {
	switch (upgradeType) {
	case 0:
		this->qualityUpgrade += value;
		break;
	case 1:
		this->storageUpgrade += value;
		break;
	case 2:
		this->priceUpgrade	 += value;
		break;
	default:
		break;
	}
}
float Products::Lemonade::GetMultiplier() {
	return 1 + (Products::basePrice * Products::Lemonade::basePriceMultiplier) + (Products::Lemonade::priceUpgrade * Products::Lemonade::priceMultiplierUpgrade);
	//1(so it's not x0.x) + Product multiplier + upgrade multiplier for total multiplier
}
char* Products::Lemonade::GetLogo() {
	char* logo = new char[1024];
	strcpy_s(logo, 1024, Products::baseLogo);
	strcat_s(logo, 1024, "Lemonade/logo.png");
	return logo;
}


Products::Coffee::Coffee() {
	this->qualityUpgrade = 1;
	this->storageUpgrade = 1;
	this->priceUpgrade	 = 1;
}
Products::Coffee::Coffee(unsigned short qualityUpgrade, unsigned short storageUpgrade, unsigned short priceUpgrade, unsigned short productUpgrade) {
	this->qualityUpgrade = qualityUpgrade;
	this->storageUpgrade = storageUpgrade;
	this->priceUpgrade = priceUpgrade;
}
void Products::Coffee::IncreaseUpgrade(unsigned short upgradeType, unsigned short value) {
	switch (upgradeType) {
	case 0:
		this->qualityUpgrade += value;
		break;
	case 1:
		this->storageUpgrade += value;
		break;
	case 2:
		this->priceUpgrade += value;
		break;
	default:
		break;
	}
}
float Products::Coffee::GetMultiplier() {
	return 1 + (Products::basePrice * Products::Coffee::basePriceMultiplier) + (Products::Coffee::priceUpgrade * Products::Coffee::priceMultiplierUpgrade);
	// Product multiplier + upgrade multiplier for total multiplier
}
char* Products::Coffee::GetLogo() {
	char* logo = new char[1024];
	strcpy_s(logo, 1024, Products::baseLogo);
	strcat_s(logo, 1024, "Coffee/logo.png");
	return logo;
}



Products::Boba::Boba() {
	this->qualityUpgrade = 1;
	this->storageUpgrade = 1;
	this->priceUpgrade	 = 1;
}
Products::Boba::Boba(unsigned short qualityUpgrade, unsigned short storageUpgrade, unsigned short priceUpgrade, unsigned short productUpgrade) {
	this->qualityUpgrade = qualityUpgrade;
	this->storageUpgrade = storageUpgrade;
	this->priceUpgrade = priceUpgrade;
}
void Products::Boba::IncreaseUpgrade(unsigned short upgradeType, unsigned short value) {
	switch (upgradeType) {
	case 0:
		this->qualityUpgrade += value;
		break;
	case 1:
		this->storageUpgrade += value;
		break;
	case 2:
		this->priceUpgrade += value;
		break;
	default:
		break;
	}
}
float Products::Boba::GetMultiplier() {
	return 1 + (Products::basePrice * Products::Boba::basePriceMultiplier) + (Products::Boba::priceUpgrade * Products::Boba::priceMultiplierUpgrade);
	//Product multiplier + upgrade multiplier for total multiplier
}
char* Products::Boba::GetLogo() {
	char* logo = new char[1024];
	strcpy_s(logo, 1024, Products::baseLogo);
	strcat_s(logo, 1024, "Boba/logo.png");
	return logo;
}




Products::Matcha::Matcha() {
	this->qualityUpgrade = 1;
	this->storageUpgrade = 1;
	this->priceUpgrade	 = 1;
}
Products::Matcha::Matcha(unsigned short qualityUpgrade, unsigned short storageUpgrade, unsigned short priceUpgrade, unsigned short productUpgrade) {
	this->qualityUpgrade = qualityUpgrade;
	this->storageUpgrade = storageUpgrade;
	this->priceUpgrade = priceUpgrade;
}
void Products::Matcha::IncreaseUpgrade(unsigned short upgradeType, unsigned short value) {
	switch (upgradeType) {
	case 0:
		this->qualityUpgrade += value;
		break;
	case 1:
		this->storageUpgrade += value;
		break;
	case 2:
		this->priceUpgrade += value;
		break;
	default:
		break;
	}
}
float Products::Matcha::GetMultiplier() {
	return 1 + (Products::basePrice * Products::Matcha::basePriceMultiplier) + (Products::Matcha::priceUpgrade * Products::Matcha::priceMultiplierUpgrade);
	//Product multiplier + upgrade multiplier for total multiplier
}
char* Products::Matcha::GetLogo() {
	char* logo = new char[1024];
	strcpy_s(logo, 1024, Products::baseLogo);
	strcat_s(logo, 1024, "Matcha/logo.png");
	return logo;
}