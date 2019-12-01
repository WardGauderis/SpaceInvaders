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

		void eventLoop();

	private:
		Game game;
		GameController gameController;
		GameView gameView;

	};

}


#endif //SPACEINVADERS_SPACEINVADERS_H
