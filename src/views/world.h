//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDVIEW_H
#define SPACEINVADERS_WORLDVIEW_H

#include "entity.h"

namespace SI::view {

	class World : public Entity {
	public:
		World(const std::shared_ptr<sf::RenderWindow>& window, const std::shared_ptr<model::Model>& model);

		void notify() override;

		void draw() override;
	};

}

#endif //SPACEINVADERS_WORLDVIEW_H
