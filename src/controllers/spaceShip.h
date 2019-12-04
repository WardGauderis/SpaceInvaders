//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_SPACESHIPCONTROLLER_H
#define SPACEINVADERS_SPACESHIPCONTROLLER_H

#include "entity.h"
#include "../views/spaceShip.h"

namespace SI::controller {

	class SpaceShip : public Entity {
	public:
		SpaceShip(const std::shared_ptr<view::SpaceShip>& view, const std::shared_ptr<model::SpaceShip>& model);

		void handleInput() override;
	};

}

#endif //SPACEINVADERS_SPACESHIPCONTROLLER_H
