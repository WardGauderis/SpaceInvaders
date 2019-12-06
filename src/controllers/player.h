//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERCONTROLLER_H
#define SPACEINVADERS_PLAYERCONTROLLER_H

#include "spaceShip.h"
#include "../views/player.h"
#include "../models/player.h"

namespace SI::controller {

	class Player : public SpaceShip {
	public:
		Player(const std::shared_ptr<model::Player>& model, const std::shared_ptr<view::Player>& view);

		void update() final;

		~Player() final = default;
	};

}

#endif //SPACEINVADERS_PLAYERCONTROLLER_H
