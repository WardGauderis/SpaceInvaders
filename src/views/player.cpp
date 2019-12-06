//
// Created by ward on 12/3/19.
//

#include "player.h"

SI::view::Player::Player(const std::shared_ptr<model::Entity>& model, const std::shared_ptr<sf::RenderWindow>& window)
		: SpaceShip(model, window) {}

void SI::view::Player::notify() {
	SpaceShip::notify();
}

void SI::view::Player::update() {
	SpaceShip::update();
}
