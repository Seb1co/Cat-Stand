#include "Settings.h"
#include "Player.h"
#include "Game.h"
#include "SFML/Graphics.hpp"

int main()
{
	SNS::Settings settings;
	settings.LoadSettings();
	Player player;
	player.LoadPlayer();
	sf::RenderWindow window(sf::VideoMode({ settings.getWidth(), settings.getHeight() }), "Cat Stand");
	Game game(player, settings);
	game.Run();


}