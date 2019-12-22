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

		bool shoot();

		unsigned int getShootChance() const;

		void setCooldown(const unsigned int cooldown);

		int getValue() const;

		void setValue(int value);

		static int getScore();

		~Enemy() final = default;

	private:
		std::uniform_int_distribution<int> distribution;

		int value;
		static int score;

		void onWallCollision(utils::Vector wall) final;

		void deleteThis() final;
	};

}

#endif //SPACEINVADERS_ENEMYMODEL_H
