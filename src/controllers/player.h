//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERCONTROLLER_H
#define SPACEINVADERS_PLAYERCONTROLLER_H

#include "../views/player.h"
#include "physicalEntity.h"

namespace SI::controller {

	class Player : public PhysicalEntity {
	public:
		Player(const std::weak_ptr<model::Player>& model, const std::weak_ptr<view::Player>& view);

		void update() final;

		~Player() final = default;
	};

}

#endif //SPACEINVADERS_PLAYERCONTROLLER_H
