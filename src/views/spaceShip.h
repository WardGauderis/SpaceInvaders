//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_SPACESHIPVIEW_H
#define SPACEINVADERS_SPACESHIPVIEW_H

#include "physicalEntity.h"
#include "../models/spaceShip.h"

namespace SI::view {

	class SpaceShip : public PhysicalEntity {
	public:
		SpaceShip(const std::weak_ptr<model::SpaceShip>& model, const std::shared_ptr<sf::RenderWindow>& window);

		~SpaceShip() override = default;
	};

}

#endif //SPACEINVADERS_SPACESHIPVIEW_H
