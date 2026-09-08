#include "Game.h"
#include "Player.h"
#include "Settings.h"
#include "SFML/Graphics.hpp"
Game::Game(const Player& player, const SNS::Settings& settings) : player(player), settings(settings) {
    this->window = sf::RenderWindow(sf::VideoMode({ this->settings.getWidth(), this->settings.getHeight() }), "Cat Stand");
    this->window.setPosition({ -7, 0 });
    drawBackground(0);
}
void Game::Run() {
    while (this->window.isOpen())
    {
        //checks for events
        while (const std::optional event = this->window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                this->window.close();
        }
    }
}
void Game::drawBackground(unsigned int currentTime) {
    //int factor = this->clock
    sf::RectangleShape grass(sf::Vector2f(this->window.getSize().x, 0.55f * this->window.getSize().y));
    grass.setFillColor(sf::Color(0, 186, 0));
    grass.setPosition({ 0, 0 });
    sf::RectangleShape pavement(sf::Vector2f(this->window.getSize().x, 0.125f * this->window.getSize().y));
    pavement.setFillColor(sf::Color(186,186,186));
    pavement.setPosition({ 0, grass.getPosition().y + grass.getSize().y });
    sf::RectangleShape road(sf::Vector2f(this->window.getSize().x, 0.325f * this->window.getSize().y));
    road.setFillColor(sf::Color(86,86,86));
    road.setPosition({ 0,pavement.getPosition().y + pavement.getSize().y });
    this->window.draw(grass);
    this->window.draw(pavement);
    this->window.draw(road);
    this->window.display();
}