//
// Created by ward on 12/8/19.
//

#include "physicalEntity.h"

void SI::model::PhysicalEntity::update() {
	move();
}

void SI::model::PhysicalEntity::move() {
	auto backup = position;
	position += velocity;
	if (std::abs(position.x) + size.x / 2 > 4) {
		velocity.x = -velocity.x * 0.5f;
		position.x = backup.x;
	}
	if (std::abs(position.y) + size.y / 2 > 3) {
		velocity.y = -velocity.y * 0.5f;
		position.y = backup.y;
	}
	velocity *= drag;
	notifyObservers();
}

void SI::model::PhysicalEntity::action(SpaceInvaders& game) {

}

void SI::model::PhysicalEntity::addVelocity(const utils::Vector& vel) {
	velocity += vel;
}

const utils::Vector& SI::model::PhysicalEntity::getPosition() const {
	return position;
}

void SI::model::PhysicalEntity::setPosition(const utils::Vector& position) {
	PhysicalEntity::position = position;
	notifyObservers();
}

const utils::Vector& SI::model::PhysicalEntity::getVelocity() const {
	return velocity;
}


void SI::model::PhysicalEntity::setVelocity(const utils::Vector& velocity) {
	PhysicalEntity::velocity = velocity;
	notifyObservers();
}

const utils::Vector& SI::model::PhysicalEntity::getSize() const {
	return size;
}

void SI::model::PhysicalEntity::setSize(const utils::Vector& size) {
	PhysicalEntity::size = size;
	notifyObservers();
}

bool SI::model::PhysicalEntity::collides(const std::shared_ptr<PhysicalEntity>& entity0,
                                         const std::shared_ptr<PhysicalEntity>& entity1) {
	return entity0->position.x - entity0->size.x / 2 < entity1->position.x + entity1->size.x / 2 &&
	       entity0->position.x + entity0->size.x / 2 > entity1->position.x - entity1->size.x / 2 &&
	       entity0->position.y - entity0->size.y / 2 < entity1->position.y + entity1->size.y / 2 &&
	       entity0->position.y + entity0->size.y / 2 > entity1->position.y - entity1->size.y / 2;
}

void SI::model::PhysicalEntity::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {

}
