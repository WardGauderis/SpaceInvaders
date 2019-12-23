//
// Created by ward on 12/19/19.
//

#ifndef SPACEINVADERS_SHIELDVIEW_H
#define SPACEINVADERS_SHIELDVIEW_H

#include "physicalEntity.h"
#include "../models/shield.h"

namespace SI::view {
	/**
	 * view class for shields
	 */
	class Shield : public PhysicalEntity {
	public:
		/**
		 * construct with correct model and window
		 * @param model pointer
		 * @param window SFML window
		 */
		Shield(const std::weak_ptr<model::Shield>& model, const std::shared_ptr<sf::RenderWindow>& window);

		/**
		 * notify the view for updates in the model
		 */
		void notify() final;

		/**
		 * function that is ran when the view is updated
		 */
		void update() final;

		/**
		 * determine in what order the objects must be drawn
		 * @return the higher the int, the later the object is updated on screen
		 */
		int drawOrder() final;
	};

}

#endif //SPACEINVADERS_SHIELDVIEW_H
