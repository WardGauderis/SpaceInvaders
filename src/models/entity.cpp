//
// Created by ward on 11/19/19.
//

#include <cmath>

#include "entity.h"

void SI::model::Entity::move() {
	const float slow = 0.99f;
	auto backup = position;
	position += velocity;
	if (std::abs(position.x) > 4) {
		velocity.x = -velocity.x * 0.5f;
		position = backup;
	}
	if (std::abs(position.y) > 3) {
		velocity.y = -velocity.y * 0.5f;
		position = backup;
	}
	velocity *= slow;
	notifyObservers();
}

void SI::model::Entity::addVelocity(const utils::Vector& vel) {
	velocity += vel;
}

const utils::Vector& SI::model::Entity::getPosition() const {
	return position;
}
