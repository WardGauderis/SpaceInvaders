//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAMEVIEW_H
#define SPACEINVADERS_GAMEVIEW_H

#include <SFML/Graphics.hpp>

#include "view.h"

namespace SI::view {

	class Game : public View {
	public:
		Game();

		void render() final;

		void notify() final;

	private:
		sf::RenderWindow window;

	};

}

#endif //SPACEINVADERS_GAMEVIEW_H
