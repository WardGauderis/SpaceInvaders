//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include <memory>

#include "../models/model.h"
#include "../views/game.h"

namespace SI::controller {

	class Controller {
	public:

		virtual void handleInput() = 0;

		virtual ~Controller() = default;
	};

}


#endif //SPACEINVADERS_CONTROLLER_H
