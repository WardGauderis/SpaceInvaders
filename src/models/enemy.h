//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYMODEL_H
#define SPACEINVADERS_ENEMYMODEL_H

#include "spaceShip.h"

namespace SI::model {

	class Enemy : public SpaceShip {
	public:
		Enemy();

		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) final;

		bool shoot();

		~Enemy() final = default;

	private:
		void onWallCollision(utils::Vector wall) final;
	};

}

#endif //SPACEINVADERS_ENEMYMODEL_H
