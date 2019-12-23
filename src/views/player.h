//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERVIEW_H
#define SPACEINVADERS_PLAYERVIEW_H

#include "spaceShip.h"
#include "../models/player.h"

namespace SI::view {
	/**
	 * view class for the player
	 */
	class Player : public SpaceShip {
	public:
		/**
		 * construct with correct model an window
		 * @param model pointer
		 * @param window SFML window
		 */
		Player(const std::weak_ptr<model::Player>& model, const std::shared_ptr<sf::RenderWindow>& window);

		~Player() final = default;

	};

}

#endif //SPACEINVADERS_PLAYERVIEW_H
