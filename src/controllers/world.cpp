//
// Created by ward on 12/3/19.
//

#include "world.h"

SI::controller::World::World(const std::shared_ptr<model::World>& model, const std::shared_ptr<view::World>& view)
		: Entity(model, view) {}

void SI::controller::World::update() {
	for (const auto& entity: entities) {
		entity->update();
	}
}

void SI::controller::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

void SI::controller::World::removeEntity(const std::shared_ptr<Entity>& entity) {
	entities.erase(entity);
}
