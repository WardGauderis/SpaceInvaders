//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_SPACESHIPVIEW_H
#define SPACEINVADERS_SPACESHIPVIEW_H

#include "entity.h"

namespace SI::view {

	class SpaceShip : public Entity {
	public:
		SpaceShip(const std::shared_ptr<model::Entity>& model, const std::shared_ptr<sf::RenderWindow>& window);

		void notify() override;

		void update() override;

		~SpaceShip() override = default;
	};

}

#endif //SPACEINVADERS_SPACESHIPVIEW_H
