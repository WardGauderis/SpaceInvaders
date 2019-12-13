//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_SPACESHIPMODEL_H
#define SPACEINVADERS_SPACESHIPMODEL_H

#include "physicalEntity.h"

namespace SI::model {

	class SpaceShip : public PhysicalEntity {
	public:
		SpaceShip(unsigned int lives);

		void shoot();

		~SpaceShip() override = default;

		unsigned int loseLive();

	private:
		unsigned int lives;
	};

}

#endif //SPACEINVADERS_SPACESHIPMODEL_H
