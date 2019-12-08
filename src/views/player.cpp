//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "../utils/transformation.h"

SI::view::Player::Player(const std::shared_ptr<model::PhysicalEntity>& model, const std::shared_ptr<sf::RenderWindow>& window)
		: SpaceShip(model, window) {
	sprite.setFillColor(sf::Color::White);
}

int SI::view::Player::drawOrder() {
	return 1;
}
