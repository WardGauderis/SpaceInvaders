//
// Created by ward on 12/9/19.
//

#include "wave.h"
#include "../utils/transformation.h"

SI::view::Wave::Wave(std::weak_ptr<model::Wave> model, const std::shared_ptr<sf::RenderWindow>& window) : Entity(
		window), model(std::move(model)), fadeInTimer(60), fadeOutTimer(300), opacity(0) {
	if (!font.loadFromFile("data/fonts/tf2build.ttf"))
		throw std::runtime_error("tf2build.ttf must be present in data/fonts");
	title.setFont(font);
	title.setCharacterSize(window->getSize().x / 30);
	notify();
}

void SI::view::Wave::notify() {
	auto m = lock();
	title.setString(m->getTitle());
	auto textRect = title.getLocalBounds();
	title.setOrigin(textRect.left + textRect.width / 2.0f,
	                textRect.top + textRect.height / 2.0f);
	title.setPosition(utils::Transformation::get().convertPoint<float>({0, 0}));

	opacity = 0;
	title.setFillColor(sf::Color(245, 231, 222, opacity));

	fadeInTimer.reset();
	fadeInTimer.start();
	fadeOutTimer.reset();
	fadeOutTimer.stop();
}

void SI::view::Wave::update() {
	fadeInTimer.update();
	fadeOutTimer.update();
	if (fadeInTimer.ready()) {
		fadeInTimer.stop();
		fadeOutTimer.start();
		fadeInTimer.setTime(0);
		title.setFillColor(sf::Color(245, 231, 222, ++opacity));
		if (opacity == 255) fadeInTimer.reset();
	}

	if (fadeOutTimer.ready()) {
		fadeOutTimer.stop();
		fadeOutTimer.setTime(0);
		title.setFillColor(sf::Color(245, 231, 222, --opacity));
		if (opacity == 0) fadeOutTimer.reset();
	}
	window->draw(title);
}

int SI::view::Wave::drawOrder() {
	return -1;
}

std::shared_ptr<SI::model::Wave> SI::view::Wave::lock() {
	auto model = Wave::model.lock();
	if (!model || model->mayDeleteThis()) deleteThis();
	return model;
}
