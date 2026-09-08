#pragma once
#include "Player.h"
#include "Settings.h"
#include "Clock.h"
#include "SFML/Graphics.hpp"
class Game
{
public:
	Game() = default;
	Game(const Player& player, const SNS::Settings& settings);
	void Run();
	Clock clock;
	sf::RenderWindow window;
	Player player;
	SNS::Settings settings;
private:
	void drawBackground(unsigned int currentTime);

};