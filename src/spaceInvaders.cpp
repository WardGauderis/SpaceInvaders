//
// Created by ward on 11/19/19.
//

#include "spaceInvaders.h"
#include "utils/stopWatch.h"

void SI::SpaceInvaders::eventLoop() {
	while (gameController.isRunning()) {
		while (utils::StopWatch::get().updateModel()) {
			gameController.handleInput();
		}
		if (utils::StopWatch::get().renderView()) {
			gameView.render();
		}
	}
}