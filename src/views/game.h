//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAMEVIEW_H
#define SPACEINVADERS_GAMEVIEW_H

#include <SFML/Graphics.hpp>

#include "view.h"
#include "../utils/event.h"

namespace SI::view {

	class Game : public View {
	public:
		Game();

		void render() final;

		void notify() final;

		bool pollEvent(utils::Event& event);

	private:
		sf::RenderWindow window;

		static bool determineKey(const sf::Keyboard::Key& sfKey, utils::Key& key);

	};

}

#endif //SPACEINVADERS_GAMEVIEW_H
