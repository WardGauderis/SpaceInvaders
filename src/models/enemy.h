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

		bool shoot();

		[[nodiscard]] unsigned int getShootChance() const;

		void setCoolDown(int coolDown);

		[[nodiscard]] int getValue() const;

		void setValue(int v);

		void deleteThis() final;

		static bool hasHitGround();

		static void restart();

		~Enemy() final = default;

	private:
		std::uniform_int_distribution<int> distribution;
		int value;

		static bool hitGround;

		void onWallCollision(utils::Vector wall) final;
	};

}

#endif //SPACEINVADERS_ENEMYMODEL_H
