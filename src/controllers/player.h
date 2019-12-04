//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERCONTROLLER_H
#define SPACEINVADERS_PLAYERCONTROLLER_H

#include "spaceShip.h"

namespace SI::controller {

	class Player : public SpaceShip {
	public:
		Player(const std::shared_ptr<view::View>& view, const std::shared_ptr<model::Entity>& model);

		void handleInput() final;

	};

}

#endif //SPACEINVADERS_PLAYERCONTROLLER_H
