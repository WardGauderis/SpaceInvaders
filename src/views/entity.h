//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYVIEW_H
#define SPACEINVADERS_ENTITYVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "../utils/observer.h"
#include "../utils/key.h"
#include "../utils/event.h"

namespace SI::view {

	class Entity : public utils::Observer {
	public:

		Entity() = default;

		Entity(std::shared_ptr<sf::RenderWindow> window);

		virtual void update() = 0;

		static bool isKeyPressed(utils::Key key);

		bool pollEvent(utils::Event& event);

		virtual ~Entity() = default;

	protected:
		std::shared_ptr<sf::RenderWindow> window;
		sf::RectangleShape sprite;

	};

}


#endif //SPACEINVADERS_ENTITYVIEW_H
