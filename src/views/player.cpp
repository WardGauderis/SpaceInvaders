//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "../utils/transformation.h"

SI::view::Player::Player(const std::weak_ptr<model::Player>& model, const std::shared_ptr<sf::RenderWindow>& window)
		: SpaceShip(model, window) {
	sprite.setFillColor(sf::Color::Blue);
}

int SI::view::Player::drawOrder() {
	return 1;
}
