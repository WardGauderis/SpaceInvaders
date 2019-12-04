//
// Created by ward on 11/19/19.
//

#include "spaceInvaders.h"
#include "utils/stopWatch.h"

SI::SpaceInvaders::SpaceInvaders() : gameModel(std::make_shared<model::Game>(model::Game())),
                                     gameView(std::make_shared<view::Game>(view::Game())),
                                     gameController(std::make_shared<controller::Game>(controller::Game(gameView))) {}

void SI::SpaceInvaders::eventLoop() {
	while (gameController->isRunning()) {
		while (utils::StopWatch::get().updateModel()) {
			gameController->handleInput();
		}
		if (utils::StopWatch::get().renderView()) {
			gameView->render();
		}
	}
}
