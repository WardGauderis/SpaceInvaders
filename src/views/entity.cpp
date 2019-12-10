//
// Created by ward on 11/25/19.
//

#include "entity.h"

SI::view::Entity::Entity(): Entity(nullptr) {}

SI::view::Entity::Entity(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)), mustDelete(false) {}

bool SI::view::Entity::mayDeleteThis() const {
	return mustDelete;
}

bool SI::view::Entity::isKeyPressed(utils::Key key) {
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
		case utils::Key::space:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
	}
	return false;
}

bool SI::view::Entity::pollEvent(utils::Event& event) {
	sf::Event sfEvent{};
	bool moreEvents;
	bool goodEvent = true;

	do {
		moreEvents = window->pollEvent(sfEvent);
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

int SI::view::Entity::drawOrder() {
	return 0;
}

void SI::view::Entity::deleteThis() {
	mustDelete = true;
}
