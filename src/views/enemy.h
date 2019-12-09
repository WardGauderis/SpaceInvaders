//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYVIEW_H
#define SPACEINVADERS_ENEMYVIEW_H

#include <unordered_set>
#include "spaceShip.h"

namespace SI::view {

	class Enemy : public SpaceShip {
	public:
		Enemy(const std::shared_ptr<model::PhysicalEntity>& model, const std::shared_ptr<sf::RenderWindow>& window);

		~Enemy() override = default;

	private:
		std::unordered_set<std::shared_ptr<Enemy>> enemies;
	};

}

#endif //SPACEINVADERS_ENEMYVIEW_H
