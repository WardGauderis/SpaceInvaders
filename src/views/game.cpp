//
// Created by ward on 12/1/19.
//

#include "game.h"

SI::view::Game::Game() : View(std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML", sf::Style::Default,
                                                                 sf::ContextSettings(0, 0, 8))) {}

void SI::view::Game::render() {
	window->display();
}

void SI::view::Game::notify() {

}
