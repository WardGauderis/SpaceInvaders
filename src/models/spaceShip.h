//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_SPACESHIPMODEL_H
#define SPACEINVADERS_SPACESHIPMODEL_H

#include "entity.h"

namespace SI::model {

	class SpaceShip : public Entity {
	public:
		SpaceShip() = default;

		~SpaceShip() override = default;
	};

}

#endif //SPACEINVADERS_SPACESHIPMODEL_H
