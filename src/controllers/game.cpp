//
// Created by ward on 12/1/19.
//

#include "game.h"

bool SI::controller::Game::isRunning() const {
	return running;
}

SI::controller::Game::Game(const std::shared_ptr<model::Game>& model, const std::shared_ptr<view::Game>& view)
		: running(true), world(std::make_shared<World>(view->getWorld(), model->getWorld())), model(model),
		  view(view) {}

void SI::controller::Game::handleInput() {
	utils::Event event{};
	while (view->pollEvent(event)) {
		switch (event.type) {
			case utils::Event::Closed:
				running = false;
				break;
		}
	}

	world->handleInput();
}