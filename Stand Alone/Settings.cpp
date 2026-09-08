#include "Settings.h"
#include <fstream>
#include "SFML\Window\Keyboard.hpp"
#define KEY sf::Keyboard::Key

/// Settings

SNS::Settings::Settings() {
	this->resolution.setResolution(1920,1080);
	this->volume.setVolume(50, 50, 50);
	this->keybinds.setKeys(KEY::Q, KEY::E, KEY::Escape);
}

SNS::Settings::Settings(SNS::Resolution resolution, SNS::Volume volume, SNS::KeyBinds keybinds) {
	this->resolution = resolution;
	this->volume = volume;
	this->keybinds = keybinds;
}

unsigned short SNS::Settings::getWidth() {
	return this->resolution.width;
}
unsigned short SNS::Settings::getHeight() {
	return this->resolution.height;
}

void SNS::Settings::LoadSettings() {
	char* save_file = new char[1024];
	char* context = nullptr;
	char* tok = nullptr;
	std::ifstream f("Settings.txt");
	while (f >> save_file) {
		tok = strtok_s(save_file, ":", &context);
		if (strcmp(tok, "Width") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			if (tok)
				this->resolution.setWidth(atoi(isdigit(tok[0]) ? tok : "1920"));
			else
				this->resolution.setWidth(1920);
		}
		else if (strcmp(tok, "Height") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			if (tok)
				this->resolution.setHeight(atoi(isdigit(tok[0]) ? tok : "1020"));
			else
				this->resolution.setHeight(1080);
		}
		else if (strcmp(tok, "MasterVolume") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			if (tok)
				this->volume.changeVolume(SNS::Volume::VolumeType::Master, atoi(isdigit(tok[0]) ? tok : "100"));
			else
				this->volume.changeVolume(SNS::Volume::VolumeType::Master, 100);
		}
		else if (strcmp(tok, "MusicVolume") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			if (tok)
				this->volume.changeVolume(SNS::Volume::VolumeType::Music, atoi(isdigit(tok[0]) ? tok : "100"));
			else
				this->volume.changeVolume(SNS::Volume::VolumeType::Music, 100);
		}
		else if (strcmp(tok, "SFXVolume") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			if (tok)
				this->volume.changeVolume(SNS::Volume::VolumeType::SFX, atoi(isdigit(tok[0]) ? tok : "100"));
			else
				this->volume.changeVolume(SNS::Volume::VolumeType::SFX, 100);
		}
		else if (strcmp(tok, "UpgradesKey") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			if (tok)
				this->keybinds.changeKey(SNS::KeyBinds::KeyType::Upgrades, (KEY)atoi(isdigit(tok[0]) ? tok : "16"));
			else
				this->keybinds.changeKey(SNS::KeyBinds::KeyType::Upgrades, KEY::Q);
		}
		else if (strcmp(tok, "InventoryKey") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			if (tok)
				this->keybinds.changeKey(SNS::KeyBinds::KeyType::Inventory, (KEY)atoi(isdigit(tok[0]) ? tok : "5"));
			else
				this->keybinds.changeKey(SNS::KeyBinds::KeyType::Inventory, KEY::E);
		}
		else if (strcmp(tok, "SettingsKey") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			if (tok)
				this->keybinds.changeKey(SNS::KeyBinds::KeyType::Settings, (KEY)atoi(isdigit(tok[0]) ? tok : "36"));
			else
				this->keybinds.changeKey(SNS::KeyBinds::KeyType::Settings, KEY::Escape);
		}
	}
	tok = nullptr;
	delete tok;
	delete[] save_file;
	context = nullptr;
	delete context;
	f.close();
}


/// RESOLUTION

/// sets the width(w) and the heigth(h) of the resolution 
void SNS::Resolution::setResolution(unsigned short w, unsigned short h) { width = w;height = h;}
/// sets the width(w) of the resolution
void SNS::Resolution::setWidth(unsigned short w) { width = w; }
/// sets the height(h) of the resolution
void SNS::Resolution::setHeight(unsigned short h) { height = h; }


/// VOLUME

/// Changes the volume based on the volumeType and the volume value passed in.
void SNS::Volume::changeVolume(unsigned short volumeType, unsigned short volume) {
	switch (volumeType)
	{
	case SNS::Volume::VolumeType::Master:	masterVolume = volume;	break;
	case SNS::Volume::VolumeType::Music:	musicVolume = volume;	break;
	case SNS::Volume::VolumeType::SFX:		sfxVolume = volume;		break;
	default:								masterVolume = volume;  break;
	}
}
/// Sets the masterVolume, musicVolume and sfxVolume to the values passed in.
void SNS::Volume::setVolume(unsigned short masterVolume, unsigned short musicVolume, unsigned short sfxVolume) {
	this->masterVolume = masterVolume;
	this->musicVolume = musicVolume;
	this->sfxVolume = sfxVolume;
}


/// KEYBINDS

/// Changes the keybind based on the key and the keyToChange value passed in.
void SNS::KeyBinds::changeKey(unsigned short key, KEY keyToChange) {
	switch (key)
	{
	case SNS::KeyBinds::KeyType::Upgrades:	openUpgrades = keyToChange;		break;
	case SNS::KeyBinds::KeyType::Inventory:	openInventory = keyToChange;	break;
	case SNS::KeyBinds::KeyType::Settings:	openSettings = keyToChange;		break;
	default:								openUpgrades = keyToChange;		break;
	}
}
/// Sets the openUpgrades, openInventory and openSettings to the values passed in.
void SNS::KeyBinds::setKeys(KEY openUpgrades, KEY openInventory, KEY openSettings) {
	this->openUpgrades = openUpgrades;
	this->openInventory = openInventory;
	this->openSettings = openSettings;
}

