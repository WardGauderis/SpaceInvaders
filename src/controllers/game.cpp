//
// Created by ward on 12/1/19.
//

#include "game.h"

bool SI::controller::Game::isRunning() const {
	return running;
}

SI::controller::Game::Game(const std::shared_ptr<view::View>& view): Controller(view) {
	running = true;
}

void SI::controller::Game::handleInput() {
	utils::Event event{};
	while (view->pollEvent(event)) {
		switch (event.type) {
			case utils::Event::Closed:
				running = false;
				break;
		}
	}
}