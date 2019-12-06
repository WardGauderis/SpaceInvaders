//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYVIEW_H
#define SPACEINVADERS_ENTITYVIEW_H

#include <SFML/Graphics.hpp>

#include "../models/entity.h"
#include "../utils/key.h"
#include "../utils/event.h"

namespace SI::view {

	class Entity : public utils::Observer {
	public:
		Entity(std::shared_ptr<model::Entity> model, std::shared_ptr<sf::RenderWindow> window);

		Entity(std::shared_ptr<model::Entity> model);

		virtual void update() = 0;

		static bool isKeyPressed(utils::Key key);

		bool pollEvent(utils::Event& event);

	protected:
		std::shared_ptr<sf::RenderWindow> window;

	private:
		std::shared_ptr<model::Entity> model;
	};

}


#endif //SPACEINVADERS_ENTITYVIEW_H
