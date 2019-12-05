//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_VIEW_H
#define SPACEINVADERS_VIEW_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "../utils/observer.h"
#include "../utils/key.h"
#include "../utils/event.h"
#include "../models/model.h"

namespace SI::view {

	class View : public utils::Observer {
	public:
		View(std::shared_ptr<sf::RenderWindow> window);

		virtual void draw() = 0;

		static bool isKeyPressed(utils::Key key);

		bool pollEvent(utils::Event& event);

		[[nodiscard]] const std::shared_ptr<sf::RenderWindow>& getWindow() const;

	protected:
		std::shared_ptr<sf::RenderWindow> window;
	};

}

#endif //SPACEINVADERS_VIEW_H
