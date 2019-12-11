//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVE_H
#define SPACEINVADERS_WAVE_H

#include "enemy.h"
#include "../models/wave.h"

namespace SI::view {

	class Wave : public Entity {
	public:
		Wave(std::weak_ptr<model::Wave> model, const std::shared_ptr<sf::RenderWindow>& window);

		void notify() override;

		void update() override;

		std::shared_ptr<model::Wave> lock();

		~Wave() override = default;

	private:
		std::weak_ptr<model::Wave> model;
	};

}

#endif //SPACEINVADERS_WAVE_H
