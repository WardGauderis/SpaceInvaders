//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERMODEL_H
#define SPACEINVADERS_PLAYERMODEL_H

#include "spaceShip.h"

namespace SI::model {

	class Player : public SpaceShip {
	public:
		Player();

		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) final;

		void update() override;

		bool shoot();

		~Player() final = default;

	private:
		const unsigned int cooldown;
		unsigned int timer;
	};

}

#endif //SPACEINVADERS_PLAYERMODEL_H
