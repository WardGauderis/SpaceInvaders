//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "../utils/transformation.h"

SI::view::Player::Player(const std::shared_ptr<model::Entity>& model, const std::shared_ptr<sf::RenderWindow>& window)
		: SpaceShip(model, window) {
	sprite.setFillColor(sf::Color::White);
	sprite.setSize({50, 50});
}

void SI::view::Player::notify() {
	SpaceShip::notify();
	auto vector = utils::Transformation::get().convert(model->getPosition());
	sprite.setPosition(vector.x, vector.y);
}

void SI::view::Player::update() {
	window->draw(sprite);
	SpaceShip::update();
}
