//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_SPACESHIPCONTROLLER_H
#define SPACEINVADERS_SPACESHIPCONTROLLER_H

#include "entity.h"

namespace SI::controller {

	class SpaceShip : public Entity {
	public:
		SpaceShip(const std::shared_ptr<view::View>& view, const std::shared_ptr<model::Entity>& model);

		void handleInput() override;
	};

}

#endif //SPACEINVADERS_SPACESHIPCONTROLLER_H
