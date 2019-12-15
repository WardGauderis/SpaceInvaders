//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYMODEL_H
#define SPACEINVADERS_ENEMYMODEL_H

#include <random>

#include "spaceShip.h"

namespace SI::model {

	class Enemy : public SpaceShip {
	public:
		Enemy();

		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) final;

		bool shoot();

		unsigned int getShootChance() const;

		void setCooldown(const unsigned int cooldown);

		static unsigned int getScore();

		~Enemy() final;

	private:
		std::uniform_int_distribution<> distribution;
		static std::default_random_engine generator;

		static unsigned int score;

		void onWallCollision(utils::Vector wall) final;
	};

}

#endif //SPACEINVADERS_ENEMYMODEL_H
