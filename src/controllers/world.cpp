//
// Created by ward on 12/3/19.
//

#include "world.h"

void SI::controller::World::handleInput() {
	player->handleInput();
}

SI::controller::World::World(const std::shared_ptr<view::View>& view, const std::shared_ptr<model::Entity>& model)
		: Entity(view, model) {}
