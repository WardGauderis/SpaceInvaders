//
// Created by ward on 12/2/19.
//

#include "spaceShip.h"

SI::view::SpaceShip::SpaceShip(const std::shared_ptr<model::PhysicalEntity>& model,
                               const std::shared_ptr<sf::RenderWindow>& window) : PhysicalEntity(model, window) {}

void SI::view::SpaceShip::notify() {
	PhysicalEntity::notify();
}

void SI::view::SpaceShip::update() {
	PhysicalEntity::update();
}
