//
// Created by ward on 12/19/19.
//

#include "shield.h"

SI::view::Shield::Shield(const std::weak_ptr<model::Shield>& model,
                         const std::shared_ptr<sf::RenderWindow>& window) : PhysicalEntity(model, window) {
	sprite.setFillColor(sf::Color(255, 255, 255, 255));
	notify();
}

int SI::view::Shield::drawOrder() {
	return 1;
}
