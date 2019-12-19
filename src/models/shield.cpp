//
// Created by ward on 12/15/19.
//

#include "shield.h"

SI::model::Shield::Shield(const utils::Vector& position) : PhysicalEntity(0, {1, 0.75}, position, {0, 0}, true) {}

void SI::model::Shield::update() {
}

void SI::model::Shield::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	PhysicalEntity::onCollision(entity);
}
