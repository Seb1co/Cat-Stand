#pragma once
namespace Products
{
	const float				basePrice					= 1.0f;
	const unsigned short	baseCustomersPD				= 30;
	const float 			baseRichCustomerChance		= 1.0f;
	const unsigned short    baseRichCustomerMultiplier	= 3;
	static const char*		baseLogo					= "assets/Products/";
	class Product {
	public:
		void IncreaseUpgrade(unsigned short upgradeType,unsigned short value);
		float GetMultiplier();
		char* GetLogo();
	};
	class Lemonade : public Product
	{
	public:
		Lemonade();
		Lemonade(unsigned short qualityUpgrade, unsigned short storageUpgrade, unsigned short priceUpgrade, unsigned short productUpgrade);
		void IncreaseUpgrade(unsigned short upgradeType, unsigned short value);;
		float GetMultiplier();
		char* GetLogo();
	private:
		const unsigned short	basePriceMultiplier = 1;		// Base price of the product
		unsigned short			priceUpgrade;					// Increases the price of the product
		const float				priceMultiplierUpgrade = 0.25f;	// Increases the price of the product

		const float				qualityMultiplier = 0.5f;		// Higher chance of richer customers
		unsigned short			qualityUpgrade;					// Higher chance of richer customers

		const float				storageMultiplier = 0.25f;		// Increases the amount of customers per day
		unsigned short			storageUpgrade;					// Increases the amount of customers per day
	};
	class Coffee : public Product {
	public:
		Coffee();
		Coffee(unsigned short qualityUpgrade, unsigned short storageUpgrade, unsigned short priceUpgrade, unsigned short productUpgrade);
		void IncreaseUpgrade(unsigned short upgradeType, unsigned short value);
		float GetMultiplier();
		char* GetLogo();
	private:
		const unsigned short	basePriceMultiplier = 2;		// Base price of the product
		unsigned short			priceUpgrade;					// Increases the price of the product
		const float				priceMultiplierUpgrade = 0.25f;	// Increases the price of the product

		const float				qualityMultiplier = 0.5f;		// Higher chance of richer customers
		unsigned short			qualityUpgrade;					// Higher chance of richer customers

		const float				storageMultiplier = 0.25f;		// Increases the amount of customers per day
		unsigned short			storageUpgrade;					// Increases the amount of customers per day
	};
	class Boba : public Product{
	public:
		Boba();
		Boba(unsigned short qualityUpgrade, unsigned short storageUpgrade, unsigned short priceUpgrade, unsigned short productUpgrade);
		void IncreaseUpgrade(unsigned short upgradeType, unsigned short value);
		float GetMultiplier();
		char* GetLogo();
	private:
		const unsigned short	basePriceMultiplier = 3;		// Base price of the product
		unsigned short			priceUpgrade;					// Increases the price of the product
		const float				priceMultiplierUpgrade = 0.25f;	// Increases the price of the product

		const float				qualityMultiplier = 0.5f;		// Higher chance of richer customers
		unsigned short			qualityUpgrade;					// Higher chance of richer customers

		const float				storageMultiplier = 0.25f;		// Increases the amount of customers per day
		unsigned short			storageUpgrade;					// Increases the amount of customers per day
	};
	class Matcha : public Product{
	public:
		Matcha();
		Matcha(unsigned short qualityUpgrade, unsigned short storageUpgrade, unsigned short priceUpgrade, unsigned short productUpgrade);
		void IncreaseUpgrade(unsigned short upgradeType, unsigned short value);
		float GetMultiplier();
		char* GetLogo();
	private:
		const unsigned short	basePriceMultiplier = 4;		// Base price of the product
		unsigned short			priceUpgrade;					// Increases the price of the product
		const float				priceMultiplierUpgrade = 0.25f;	// Increases the price of the product

		const float				qualityMultiplier = 0.5f;		// Higher chance of richer customers
		unsigned short			qualityUpgrade;					// Higher chance of richer customers

		const float				storageMultiplier = 0.25f;		// Increases the amount of customers per day
		unsigned short			storageUpgrade;					// Increases the amount of customers per day
	};
}

