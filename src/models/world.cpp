//
// Created by ward on 12/3/19.
//

#include "world.h"

void SI::model::World::update() {

}

void SI::model::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

void SI::model::World::removeEntity(const std::shared_ptr<Entity>& entity) {
	entities.erase(entity);
}
