//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERMODEL_H
#define SPACEINVADERS_PLAYERMODEL_H

#include "spaceShip.h"

namespace SI::model {

	class Player : public SpaceShip {
	public:
		void update() final;
	};

}

#endif //SPACEINVADERS_PLAYERMODEL_H
