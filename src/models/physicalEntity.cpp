//
// Created by ward on 12/8/19.
//

#include "explosion.h"

SI::model::PhysicalEntity::PhysicalEntity(float drag, const utils::Vector& size, const utils::Vector& position,
                                          const utils::Vector& velocity, bool team)
		: drag(drag), position(position), velocity(velocity), team(team) {
	setSize(size);
}

void SI::model::PhysicalEntity::update() {
	move();
	if (auto vector = detectWallCollision())
		onWallCollision(vector);
	notifyObservers();
}

void SI::model::PhysicalEntity::addVelocity(const utils::Vector& vel) { velocity += vel; }

const utils::Vector& SI::model::PhysicalEntity::getPosition() const { return position; }

void SI::model::PhysicalEntity::setPosition(const utils::Vector& pos) { PhysicalEntity::position = pos; }

const utils::Vector& SI::model::PhysicalEntity::getVelocity() const { return velocity; }

void SI::model::PhysicalEntity::setVelocity(const utils::Vector& vel) { PhysicalEntity::velocity = vel; }

const utils::Vector& SI::model::PhysicalEntity::getSize() const { return size; }

void SI::model::PhysicalEntity::setSize(const utils::Vector& s) {
	if (s.x < 0 || s.y < 0)
		throw std::runtime_error("size must be positive");
	if (s.x > 7 || s.y > 5)
		throw std::runtime_error("size is too big");
	PhysicalEntity::size = s;
}

bool SI::model::PhysicalEntity::getTeam() const { return team; }

bool SI::model::PhysicalEntity::collidesWith(const std::shared_ptr<PhysicalEntity>& entity) {
	bool collision = AABB(position - size / 2, size, entity->position - entity->size / 2, entity->size);
	return collision;
}

bool SI::model::PhysicalEntity::AABB(const utils::Vector p0, const utils::Vector s0, const utils::Vector p1,
                                     const utils::Vector s1) {
	return p0.x < p1.x + s1.x && p0.x + s0.x > p1.x && p0.y < p1.y + s1.y && p0.y + s0.y > p1.y;
}

void SI::model::PhysicalEntity::onCollision([[maybe_unused]] const std::shared_ptr<PhysicalEntity>& entity) {
	velocity.x = -velocity.x;
}

void SI::model::PhysicalEntity::deleteThis() {
	addModel(std::make_shared<Explosion>(*this));
	Entity::deleteThis();
}

void SI::model::PhysicalEntity::move() {
	position += velocity;
	velocity *= drag;
}

utils::Vector SI::model::PhysicalEntity::detectWallCollision() const {
	utils::Vector wall;
	if (position.x + size.x / 2 > 4)
		wall.x = 4;
	else if (position.x - size.x / 2 < -4)
		wall.x = -4;
	if (position.y + size.y / 2 > 3)
		wall.y = 3;
	else if (position.y - size.y / 2 < -2.75f)
		wall.y = -2.75f;
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
