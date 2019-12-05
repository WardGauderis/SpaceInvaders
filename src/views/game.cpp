//
// Created by ward on 12/1/19.
//

#include "game.h"

SI::view::Game::Game(const std::shared_ptr<model::Game>& model) : View(
		std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML", sf::Style::Default,
		                                   sf::ContextSettings(0, 0, 8))), model(model),
                                                                  world(std::make_shared<World>(window,
                                                                                                model->getWorld())) {}

void SI::view::Game::draw() {
	window->display();
}

void SI::view::Game::notify() {

}

const std::shared_ptr<SI::view::World>& SI::view::Game::getWorld() const {
	return world;
}
