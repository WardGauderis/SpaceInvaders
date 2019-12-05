//
// Created by ward on 12/3/19.
//

#include "world.h"
#include "../models/world.h"

SI::view::World::World(const std::shared_ptr<sf::RenderWindow>& window, const std::shared_ptr<model::World>& model)
		: Entity(window, model) {}

void SI::view::World::draw() {

}

void SI::view::World::notify() {

}
