//
// Created by ward on 11/19/19.
//

#include "spaceInvaders.h"
#include "utils/stopWatch.h"
#include <thread>

SI::SpaceInvaders::SpaceInvaders() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Default,
	                                            settings);

	sf::Vector2i localPosition;

	while (window->isOpen()) {
		sf::Event event{};

		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
			else if (event.type == sf::Event::MouseButtonPressed) {

			}
		}
		window->clear(sf::Color::Black);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			localPosition = sf::Mouse::getPosition(*window);
		}

		double fps;

		sf::Font font;
		font.loadFromFile("UbuntuMono-R.ttf");
		sf::Text text(std::to_string(localPosition.x) + ", " + std::to_string(localPosition.y), font);
		text.setPosition(0.1f, 1.5f);
		text.setFillColor(sf::Color::White);
		window->draw(text);

		window->display();
		std::this_thread::sleep_for(33ms);
	}

}
