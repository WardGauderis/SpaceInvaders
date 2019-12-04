//
// Created by ward on 11/19/19.
//

#include "entity.h"

void SI::model::Entity::move() {
	velocity += acceleration;
	position += velocity;
	notifyObservers();
}

void SI::model::Entity::addAcceleration(const utils::Vector& acc) {
	acceleration += acc;
}
