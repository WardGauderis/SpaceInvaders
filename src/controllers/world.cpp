//
// Created by ward on 12/3/19.
//

#include "world.h"

#include <utility>

SI::controller::World::World(std::shared_ptr<model::World>  model, std::shared_ptr<view::World>  view)
		: model(std::move(model)), view(std::move(view)) {}

void SI::controller::World::update(SpaceInvaders& game) {
	for (const auto& entity: entities) {
		entity->update(game);
	}
}

void SI::controller::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

void SI::controller::World::removeEntity(const std::shared_ptr<Entity>& entity) {
	entities.erase(entity);
}
