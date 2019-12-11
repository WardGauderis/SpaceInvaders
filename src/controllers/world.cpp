//
// Created by ward on 12/3/19.
//

#include "world.h"

SI::controller::World::World(std::shared_ptr<model::World>  model, std::shared_ptr<view::World>  view)
		: model(std::move(model)), view(std::move(view)) {}

void SI::controller::World::update() {
	for (const auto& entity: entities) {
		entity->update();
	}
}

void SI::controller::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

 void SI::controller::World::removeEntities() {
	for (auto it = entities.begin(); it != entities.end();) {
		if((*it)->mayDeleteThis()) it = entities.erase(it);
		else ++it;
	}
}
