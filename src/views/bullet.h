//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_BULLETVIEW_H
#define SPACEINVADERS_BULLETVIEW_H

#include "physicalEntity.h"
#include "../models/bullet.h"

namespace SI::view {
	/**
	 * view class for bullets
	 */
	class Bullet : public PhysicalEntity {
	public:
		/**
		 * construct with correct model and window
		 * @param model pointer
		 * @param window SFML window
		 */
		Bullet(const std::weak_ptr<model::Bullet>& model, const std::shared_ptr<sf::RenderWindow>& window);

		~Bullet() final = default;
	};

}

#endif //SPACEINVADERS_BULLETVIEW_H
