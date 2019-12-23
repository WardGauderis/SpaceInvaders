//
// Created by ward on 11/25/19.
//

#include "entity.h"

SI::controller::Entity::Entity() : mustDelete(false) {}

bool SI::controller::Entity::mayDeleteThis() const { return mustDelete; }

void SI::controller::Entity::deleteThis() { mustDelete = true; }
