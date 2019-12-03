//
// Created by ward on 12/2/19.
//

#include "view.h"

bool SI::view::View::isKeyPressed(const utils::Key key) {
	switch (key) {
		case utils::Key::up:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
			       sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z);
		case utils::Key::down:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
			       sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
		case utils::Key::left:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
			       sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
		case utils::Key::right:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
			       sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
	}
}

bool SI::view::View::pollEvent(utils::Event& event) {
	sf::Event sfEvent{};
	bool moreEvents;
	bool goodEvent = true;

	do {
		moreEvents = window.pollEvent(sfEvent);
		if (!moreEvents) return moreEvents;
		switch (sfEvent.type) {
			case sf::Event::Closed:
				event.type = utils::Event::Closed;
				break;
			default:
				goodEvent = false;
		}
	} while (!goodEvent);

	return moreEvents;

}
