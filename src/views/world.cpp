//
// Created by ward on 12/3/19.
//

#include "world.h"

SI::view::World::World(const std::shared_ptr<sf::RenderWindow>& window, const std::shared_ptr<model::World>& model)
		: Entity(window, model) {}

void SI::view::World::draw() {

}

void SI::view::World::notify() {

}

void SI::view::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

void SI::view::World::removeEntity(const std::shared_ptr<Entity>& entity) {
	entities.erase(entity);
}
