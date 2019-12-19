//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYCONTROLLER_H
#define SPACEINVADERS_ENEMYCONTROLLER_H

#include "../views/enemy.h"
#include "physicalEntity.h"

namespace SI::controller {

	class Enemy : public PhysicalEntity {
	public:
		Enemy(const std::weak_ptr<model::Enemy>& model, const std::weak_ptr<view::Enemy>& view);

		void update() final;

		~Enemy() final = default;
	};

}

#endif //SPACEINVADERS_ENEMYCONTROLLER_H
