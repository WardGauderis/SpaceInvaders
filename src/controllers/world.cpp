//
// Created by ward on 12/3/19.
//

#include "world.h"

void SI::controller::World::handleInput() {
	for (const auto& entity: entities) {
		entity->handleInput();
	}
}

SI::controller::World::World(const std::shared_ptr<view::World>& view, const std::shared_ptr<model::World>& model)
		: Entity(view, model) {}

void SI::controller::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

void SI::controller::World::removeEntity(const std::shared_ptr<Entity>& entity) {
	entities.erase(entity);
}
