//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_SPACESHIPCONTROLLER_H
#define SPACEINVADERS_SPACESHIPCONTROLLER_H

#include "physicalEntity.h"
#include "../views/spaceShip.h"
#include "../models/spaceShip.h"

namespace SI::controller {

	class SpaceShip : public PhysicalEntity {
	public:
		SpaceShip(const std::shared_ptr<model::SpaceShip>& model, const std::shared_ptr<view::SpaceShip>& view);

		void update(SpaceInvaders& game) override;

		~SpaceShip() override = default;
	};

}

#endif //SPACEINVADERS_SPACESHIPCONTROLLER_H
