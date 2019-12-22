//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERMODEL_H
#define SPACEINVADERS_PLAYERMODEL_H

#include "spaceShip.h"
#include "../utils/stopWatch.h"

namespace SI::model {

	class Player : public SpaceShip {
	public:
		Player();

		void update() final;

		unsigned int loseLive() override;

		bool shoot();

		static int getScore();

		static void addScore(int score);

		static void resetScore();

		~Player() final = default;

	private:
		utils::Timer timer;

		static int score;
	};

}

#endif //SPACEINVADERS_PLAYERMODEL_H
