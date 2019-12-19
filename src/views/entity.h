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

		Entity();

		explicit Entity(std::shared_ptr<sf::RenderWindow> window);

		virtual void update() = 0;

		[[nodiscard]] bool mayDeleteThis() const;

		static bool isKeyPressed(utils::Key key);

		bool pollEvent(utils::Event& event);

		virtual int drawOrder();

		virtual ~Entity() = default;

	protected:
		std::shared_ptr<sf::RenderWindow> window;

		void deleteThis();

	private:
		bool mustDelete;
	};

}


#endif //SPACEINVADERS_ENTITYVIEW_H
