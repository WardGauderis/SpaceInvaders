//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYCONTROLLER_H
#define SPACEINVADERS_ENEMYCONTROLLER_H

#include "spaceShip.h"
#include "../views/enemy.h"

namespace SI::controller {

	class Enemy : public SpaceShip {
	public:
		Enemy(const std::weak_ptr<model::Enemy>& model, const std::weak_ptr<view::Enemy>& view);

		~Enemy() override = default;
	};

}

#endif //SPACEINVADERS_ENEMYCONTROLLER_H
