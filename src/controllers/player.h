//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERCONTROLLER_H
#define SPACEINVADERS_PLAYERCONTROLLER_H

#include "spaceShip.h"

namespace SI::controller {

	class Player : public SpaceShip {
	public:
		void handleInput() final;

	private:

	};

}

#endif //SPACEINVADERS_PLAYERCONTROLLER_H
