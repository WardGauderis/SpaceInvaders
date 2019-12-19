//
// Created by ward on 12/8/19.
//

#include "physicalEntity.h"
#include "explosion.h"

SI::model::PhysicalEntity::PhysicalEntity(float drag, const utils::Vector& size, const utils::Vector& position,
                                          const utils::Vector& velocity, bool team) : drag(drag), position(position),
                                                                           velocity(velocity), team(team) {
	setSize(size);
}

void SI::model::PhysicalEntity::update() {
	move();
	if (auto vector = detectWallCollision())
		onWallCollision(vector);
	notifyObservers();
}

void SI::model::PhysicalEntity::addVelocity(const utils::Vector& vel) {
	velocity += vel;
}

const utils::Vector& SI::model::PhysicalEntity::getPosition() const {
	return position;
}

void SI::model::PhysicalEntity::setPosition(const utils::Vector& position) {
	PhysicalEntity::position = position;
}

const utils::Vector& SI::model::PhysicalEntity::getVelocity() const {
	return velocity;
}


void SI::model::PhysicalEntity::setVelocity(const utils::Vector& velocity) {
	PhysicalEntity::velocity = velocity;
}

const utils::Vector& SI::model::PhysicalEntity::getSize() const {
	return size;
}

void SI::model::PhysicalEntity::setSize(const utils::Vector& size) {
	if (size.x < 0 || size.y < 0) throw std::runtime_error("size must be positive");
	if (size.x > 7 || size.y > 5) throw std::runtime_error("size is too big");
	PhysicalEntity::size = size;
}

bool SI::model::PhysicalEntity::getTeam() const {
	return team;
}

void SI::model::PhysicalEntity::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	velocity.x = -velocity.x;
}

bool SI::model::PhysicalEntity::detectCollision(const std::shared_ptr<PhysicalEntity>& entity0,
                                                const std::shared_ptr<PhysicalEntity>& entity1) {
	return entity0->position.x - entity0->size.x / 2 < entity1->position.x + entity1->size.x / 2 &&
	       entity0->position.x + entity0->size.x / 2 > entity1->position.x - entity1->size.x / 2 &&
	       entity0->position.y - entity0->size.y / 2 < entity1->position.y + entity1->size.y / 2 &&
	       entity0->position.y + entity0->size.y / 2 > entity1->position.y - entity1->size.y / 2;
}

void SI::model::PhysicalEntity::move() {
	position += velocity;
	velocity *= drag;
}

utils::Vector SI::model::PhysicalEntity::detectWallCollision() const {
	utils::Vector wall;
	if (position.x + size.x / 2 > 4) wall.x = 4;
	else if (position.x - size.x / 2 < -4) wall.x = -4;
	if (position.y + size.y / 2 > 3) wall.y = 3;
	else if (position.y - size.y / 2 < -2.75f) wall.y = -2.75f;
	return wall;
}

void SI::model::PhysicalEntity::onWallCollision(utils::Vector wall) {
	if (static_cast<bool>(wall.x)) {
		velocity.x = -velocity.x;
		auto delta = position.x + size.x / 2 * utils::getSign(wall.x) - wall.x;
		position.x -= 2 * delta * drag;
	}
	if (static_cast<bool>(wall.y)) {
		velocity.y = -velocity.y;
		auto delta = position.y + size.y / 2 * utils::getSign(wall.y) - wall.y;
		position.y -= 2 * delta * drag;
	}
}

void SI::model::PhysicalEntity::deleteThis() {
	addModel(std::make_shared<Explosion>(*this));
	Entity::deleteThis();
}