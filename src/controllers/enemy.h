//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYCONTROLLER_H
#define SPACEINVADERS_ENEMYCONTROLLER_H

#include "spaceShip.h"

namespace SI::controller {

	class Enemy : public SpaceShip {
	public:
		Enemy(const std::shared_ptr<model::SpaceShip>& model, const std::shared_ptr<view::SpaceShip>& view);

		~Enemy() override = default;
	};

}

#endif //SPACEINVADERS_ENEMYCONTROLLER_H
