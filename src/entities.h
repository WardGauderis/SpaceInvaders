//
// Created by ward on 12/7/19.
//

#ifndef SPACEINVADERS_ENTITIES_H
#define SPACEINVADERS_ENTITIES_H

#endif //SPACEINVADERS_ENTITIES_H

#include "controllers/player.h"

namespace SI {

	struct Player {
		using Model = model::Player;
		using View = view::Player;
		using Controller = controller::Player;
	};

}