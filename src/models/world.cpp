//
// Created by ward on 12/3/19.
//

#include "world.h"

void SI::model::World::update() {
	for (const auto& entity: entities) {
		entity->update();
	}
	for (auto it0 = physicalEntities.begin(); it0 != physicalEntities.end(); ++it0) {
		auto& entity0 = (*it0);
		auto it1 = it0;
		++it1;
		for (; it1 != physicalEntities.end(); ++it1) {
			auto& entity1 = (*it1);
			if (model::PhysicalEntity::detectCollision(entity0, entity1)) {
				entity0->onCollision(entity1);
				entity1->onCollision(entity0);
			}
		}
	}
}

void SI::model::World::addEntity(const std::shared_ptr<Entity>& entity) {
	if(entity == nullptr) return;
	if (auto physicalEntity = std::dynamic_pointer_cast<PhysicalEntity>(entity))
		physicalEntities.emplace(physicalEntity);
	entities.emplace(entity);
}


std::vector<std::shared_ptr<SI::model::Entity>> SI::model::World::getNewModels() {
	for (const auto& entity: entities) {
		addModels(entity->getNewModels());
	}
	return Entity::getNewModels();
}

void SI::model::World::removeEntities() {
	for (auto it = entities.begin(); it != entities.end();) {
		if ((*it)->mayDeleteThis())
			it = entities.erase(it);
		else ++it;
	}
	for (auto it = physicalEntities.begin(); it != physicalEntities.end();) {
		if ((*it)->mayDeleteThis()) it = physicalEntities.erase(it);
		else ++it;
	}
}