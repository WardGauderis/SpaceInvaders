//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERVIEW_H
#define SPACEINVADERS_PLAYERVIEW_H

#include "spaceShip.h"

namespace SI::view {

	class Player : public SpaceShip {
	public:
		Player(const std::shared_ptr<model::PhysicalEntity>& model, const std::shared_ptr<sf::RenderWindow>& window);

		int drawOrder() override;

		~Player() final = default;

	};

}

#endif //SPACEINVADERS_PLAYERVIEW_H
