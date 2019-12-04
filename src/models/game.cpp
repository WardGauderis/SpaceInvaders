//
// Created by ward on 12/1/19.
//

#include "game.h"

void SI::model::Game::update() {

}

SI::model::Game::Game(): Model(), world(std::make_shared<World>()) {}

const std::shared_ptr<SI::model::World>& SI::model::Game::getWorld() const {
	return world;
}
