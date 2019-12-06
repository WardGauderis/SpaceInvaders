//
// Created by ward on 11/25/19.
//

#include "entity.h"

#include <utility>

SI::view::Entity::Entity(std::shared_ptr<model::Entity>  model, std::shared_ptr<sf::RenderWindow>  window)
		: model(std::move(model)), window(std::move(window)) {}

SI::view::Entity::Entity(std::shared_ptr<model::Entity> model): Entity(std::move(model), nullptr) {}

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
