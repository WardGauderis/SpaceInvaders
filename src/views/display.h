//
// Created by ward on 12/15/19.
//

#ifndef SPACEINVADERS_DISPLAY_H
#define SPACEINVADERS_DISPLAY_H

#include "entity.h"
#include "../models/player.h"
#include "../models/wave.h"

namespace SI::view {

	class Display : public Entity {
	public:
		Display(const std::shared_ptr<sf::RenderWindow>& window, std::weak_ptr<model::Player> playerModel,
		        std::weak_ptr<model::Wave> waveModel);

		void notify() final;

		void update() final;

		int drawOrder() final;

		~Display() final = default;

	private:
		std::weak_ptr<model::Player> playerModel;
		std::weak_ptr<model::Wave> waveModel;

		sf::RectangleShape bar;
		sf::Font font;

		sf::Text lives;
		sf::Text score;
		sf::Text waveNumber;

		std::pair<std::shared_ptr<model::Player>, std::shared_ptr<model::Wave>> lock();
	};

}

#endif //SPACEINVADERS_DISPLAY_H
