//
// Created by ward on 12/3/19.
//

#include "player.h"

SI::view::Player::Player(const std::weak_ptr<model::Player>& model, const std::shared_ptr<sf::RenderWindow>& window)
		: SpaceShip(model, window) {
	sprite.setFillColor(sf::Color(43, 143, 200));
}