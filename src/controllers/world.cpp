//
// Created by ward on 12/3/19.
//

#include "world.h"

void SI::controller::World::handleInput() {
	player->handleInput();
}

SI::controller::World::World(const std::shared_ptr<view::World>& view, const std::shared_ptr<model::World>& model)
		: Entity(view, model) {}
