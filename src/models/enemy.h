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

		~Enemy() override = default;
	};

}

#endif //SPACEINVADERS_ENEMYMODEL_H
