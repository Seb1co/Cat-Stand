#pragma once
namespace Items
{
	class Item {
	public:
		char* name = nullptr;
		const float multiplier = 0.f;
	};

	class QualityPotion : public Item{
		QualityPotion();
		char* name = nullptr;
		unsigned short chanceWeight;
		const float multiplier = 0.15f;
	};

	class StoragePotion : public Item {
		StoragePotion();
		char* name = nullptr;
		unsigned short chanceWeight;
		const float multiplier = 0.15f;
	};

	class PricePotion : public Item {
		PricePotion();
		char* name = nullptr;
		unsigned short chanceWeight;
		const float multiplier = 0.15f;
	};

}
