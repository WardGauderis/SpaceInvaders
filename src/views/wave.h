//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVE_H
#define SPACEINVADERS_WAVE_H

#include "enemy.h"
#include "../models/wave.h"
#include "../utils/stopWatch.h"

namespace SI::view {

	class Wave : public Entity {
	public:
		Wave(std::weak_ptr<model::Wave> model, const std::shared_ptr<sf::RenderWindow>& window);

		void notify() final;

		void update() final;

		int drawOrder() final;

		std::shared_ptr<model::Wave> lock();

		~Wave() final = default;

	private:
		std::weak_ptr<model::Wave> model;
		sf::Font font;
		sf::Text text;

		utils::Timer timer;
		uint8_t opacity;
	};

}

#endif //SPACEINVADERS_WAVE_H
