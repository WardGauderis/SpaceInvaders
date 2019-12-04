//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAMECONTROLLER_H
#define SPACEINVADERS_GAMECONTROLLER_H

#include "controller.h"
#include "world.h"

namespace SI::controller {

	class Game : public Controller {
	public:
		explicit Game(const std::shared_ptr<model::Game>& model, const std::shared_ptr<view::Game>& view);

		[[nodiscard]] bool isRunning() const;

		void handleInput() final;

	private:
		bool running;
		std::shared_ptr<World> world;

	};

}

#endif //SPACEINVADERS_GAMECONTROLLER_H
