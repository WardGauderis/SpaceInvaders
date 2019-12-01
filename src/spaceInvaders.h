//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_SPACEINVADERS_H
#define SPACEINVADERS_SPACEINVADERS_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace SI {

	class SpaceInvaders {
	public:
		SpaceInvaders();

	private:
		std::shared_ptr<sf::RenderWindow> window;


	};

}


#endif //SPACEINVADERS_SPACEINVADERS_H
