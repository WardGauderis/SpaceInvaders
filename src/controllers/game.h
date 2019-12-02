//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAMECONTROLLER_H
#define SPACEINVADERS_GAMECONTROLLER_H

#include "controller.h"
#include "../views/game.h"

namespace SI::controller {

	class Game : public Controller {
	public:
		Game();

		[[nodiscard]] bool isRunning() const;

		void handleInput();

	private:
		bool running;
		std::shared_ptr<view::Game> view;

		void handleKey(utils::Key key);
	};

}

#endif //SPACEINVADERS_GAMECONTROLLER_H
