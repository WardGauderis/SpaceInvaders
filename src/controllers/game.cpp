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

void SI::controller::Game::handleInput() {
	utils::Event event{};
	while (view->pollEvent(event)) {
		switch (event.type) {
			case utils::Event::Closed:
				running = false;
				break;
			case utils::Event::KeyPressed:

		}
	}
}

void SI::controller::Game::handleKey(const utils::Key key) {
	switch (key) {
		case utils::Key::up:
		case utils::Key::down:
		case utils::Key::left:
		case utils::Key::right:

	}
}
