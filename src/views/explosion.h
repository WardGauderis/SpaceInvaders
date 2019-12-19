//
// Created by ward on 12/19/19.
//

#ifndef SPACEINVADERS_EXPLOSIONVIEW_H
#define SPACEINVADERS_EXPLOSIONVIEW_H

#include "entity.h"
#include "../models/explosion.h"

namespace SI::view {

	class Explosion : public Entity {
	public:
		Explosion(std::weak_ptr<model::Explosion> model, const std::shared_ptr<sf::RenderWindow>& window);

		void notify() final;

		void update() final;

		int drawOrder() final;

		~Explosion() final = default;

	private:
		std::weak_ptr<model::Explosion> model;
		sf::RectangleShape sprite;

		std::shared_ptr<model::Explosion> lock();
	};

}

#endif //SPACEINVADERS_EXPLOSIONVIEW_H
