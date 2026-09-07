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

void SNS::Settings::LoadSettingss() {
	char* save_file = new char[1024];
	char* context = nullptr;
	std::ifstream f("Settings.txt");
	while (f >> save_file) {
		char* tok = strtok_s(save_file, ":", &context);
		if (strcmp(tok, "Width") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			this->resolution.setWidth(atoi(tok));
		}
		else if (strcmp(tok, "Height") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			this->resolution.setHeight(atoi(tok));
		}
		else if (strcmp(tok, "MasterVolume") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			this->volume.changeVolume(SNS::Volume::VolumeType::Master, atoi(tok));
		}
		else if (strcmp(tok, "MusicVolume") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			this->volume.changeVolume(SNS::Volume::VolumeType::Music, atoi(tok));
		}
		else if (strcmp(tok, "SFXVolume") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			this->volume.changeVolume(SNS::Volume::VolumeType::SFX, atoi(tok));
		}
		else if (strcmp(tok, "UpgradesKey") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			this->keybinds.changeKey(SNS::KeyBinds::KeyType::Upgrades, (KEY)atoi(tok));
		}
		else if (strcmp(tok, "InventoryKey") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			this->keybinds.changeKey(SNS::KeyBinds::KeyType::Inventory, (KEY)atoi(tok));
		}
		else if (strcmp(tok, "SettingsKey") == 0) {
			tok = strtok_s(nullptr, ":", &context);
			this->keybinds.changeKey(SNS::KeyBinds::KeyType::Settings, (KEY)atoi(tok));
		}
	}
	delete save_file;
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

