//
// Created by ward on 12/1/19.
//

#include "game.h"

SI::view::Game::Game() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(800, 600), "SFML", sf::Style::Default, settings);
}

void SI::view::Game::render() {
	window.display();
}

void SI::view::Game::notify() {

}

bool SI::view::Game::pollEvent(utils::Event& event) {
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
			case sf::Event::KeyPressed:
				event.type = utils::Event::KeyPressed;
				goodEvent = determineKey(sfEvent.key.code, event.key.code);
				break;
			default:
				goodEvent = false;
		}
	} while (!goodEvent);

	return moreEvents;
}

bool SI::view::Game::determineKey(const sf::Keyboard::Key& sfKey, utils::Key& key) {
	switch (sfKey) {
		case sf::Keyboard::Key::Up:
		case sf::Keyboard::Key::Z:
			key = utils::Key::up;
			break;
		case sf::Keyboard::Key::Down:
		case sf::Keyboard::Key::S:
			key = utils::Key::down;
			break;
		case sf::Keyboard::Key::Left:
		case sf::Keyboard::Key::Q:
			key = utils::Key::left;
			break;
		case sf::Keyboard::Key::Right:
		case sf::Keyboard::Key::D:
			key = utils::Key::right;
			break;
		default:
			return false;
	}
	return true;
}
