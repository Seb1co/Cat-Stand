#pragma once
#include "SFML\Window\Keyboard.hpp"
#define KEY sf::Keyboard::Key
namespace SNS {
	struct Resolution
	{
		unsigned short width;
		unsigned short height;
		void setResolution(unsigned short w, unsigned short h);
		void setWidth(unsigned short w);
		void setHeight(unsigned short h);
	};
	struct Volume {
		unsigned short masterVolume;
		unsigned short musicVolume;
		unsigned short sfxVolume;
		enum VolumeType
		{
			Master,
			Music,
			SFX
		};
		void changeVolume(unsigned short volumeType, unsigned short volume);
		void setVolume(unsigned short masterVolume, unsigned short musicVolume, unsigned short sfxVolume);
	};
	struct KeyBinds {
		KEY openUpgrades;
		KEY openInventory;
		KEY openSettings;
		enum KeyType
		{
			Upgrades,
			Settings,
			Inventory
		};
		void changeKey(unsigned short key, KEY keyToChange);
		void setKeys(KEY openUpgrades, KEY openInventory, KEY openSettings);
	};

	class Settings
	{
	public:
		Settings();
		Settings(SNS::Resolution resolution, SNS::Volume volume, SNS::KeyBinds keybinds);
		void LoadSettingss();
	private:
		SNS::Resolution resolution;
		SNS::Volume		volume;
		SNS::KeyBinds	keybinds;
	};
	
}


