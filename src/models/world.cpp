//
// Created by ward on 12/3/19.
//

#include "world.h"

void SI::model::World::update() {
	for (const auto& entity: entities) {
		entity->update();
	}
	for (auto it0 = physicalEntities.begin(); it0 != physicalEntities.end(); ++it0) {
		for (auto it1 = it0; it1 != physicalEntities.end(); ++it1) {
			if (model::PhysicalEntity::collides(*it0, *it1)) {
				(*it0)->onCollision(*it1);
				(*it1)->onCollision(*it0);
			}
		}
	}
}

void SI::model::World::addEntity(const std::shared_ptr<Entity>& entity) {
	if (auto physicalEntity = std::dynamic_pointer_cast<PhysicalEntity>(entity))
		physicalEntities.emplace(physicalEntity);
	entities.emplace(entity);
}

void SI::model::World::removeEntity(const std::shared_ptr<Entity>& entity) {
	if (auto physicalEntity = std::dynamic_pointer_cast<PhysicalEntity>(entity))
		physicalEntities.erase(physicalEntity);
	entities.erase(entity);
}
