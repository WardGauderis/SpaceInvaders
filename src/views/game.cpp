//
// Created by ward on 12/1/19.
//

#include "game.h"

SI::view::Game::Game() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(800, 600), "SFML", sf::Style::Default, settings);
}

void SI::view::Game::render() {
	window.display();
}

void SI::view::Game::notify() {

}
