//
// Created by ward on 12/1/19.
//

#include "game.h"

bool SI::controller::Game::isRunning() const {
	return running;
}

SI::controller::Game::Game() {
	running = true;
}
