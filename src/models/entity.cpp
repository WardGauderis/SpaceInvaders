//
// Created by ward on 11/19/19.
//

#include "entity.h"

SI::model::Entity::Entity(): mustDelete(false) {}

bool SI::model::Entity::mayDeleteThis() const {
	return mustDelete;
}

void SI::model::Entity::deleteThis() {
	mustDelete = true;
}
