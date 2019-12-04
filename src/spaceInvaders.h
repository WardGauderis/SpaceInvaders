//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_SPACEINVADERS_H
#define SPACEINVADERS_SPACEINVADERS_H

#include "models/game.h"
#include "controllers/game.h"
#include "views/game.h"

namespace SI {

	class SpaceInvaders {
	public:
		SpaceInvaders();

		void eventLoop();

	private:
		std::shared_ptr<model::Game> gameModel;
		std::shared_ptr<view::Game> gameView;
		std::shared_ptr<controller::Game> gameController;
	};

}


#endif //SPACEINVADERS_SPACEINVADERS_H
