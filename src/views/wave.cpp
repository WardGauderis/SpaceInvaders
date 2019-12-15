//
// Created by ward on 12/9/19.
//

#include "wave.h"

SI::view::Wave::Wave(std::weak_ptr<model::Wave> model, const std::shared_ptr<sf::RenderWindow>& window) : Entity(
		window), model(std::move(model)), timer(300), opacity(255) {
	font.loadFromFile("data/fonts/tf2build.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color(245, 231, 222, opacity));
	notify();
}

void SI::view::Wave::notify() {
	auto m = lock();
	text.setString(m->getTitle());
	text.setCharacterSize(window->getSize().x / 30);
	auto textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
	               textRect.top + textRect.height / 2.0f);
	text.setPosition(window->getSize().x / 2, window->getSize().y / 2);

	opacity = 255;
	text.setFillColor(sf::Color(245, 231, 222, opacity));
	timer.reset();
	timer.start();
}

void SI::view::Wave::update() {
	timer.update();
	if (timer.ready()){
		timer.stop();
		timer.setTime(0);
		text.setFillColor(sf::Color(245, 231, 222, --opacity));
		if(opacity == 0) timer.reset();
	}
	window->draw(text);
}

int SI::view::Wave::drawOrder() {
	return -1;
}

std::shared_ptr<SI::model::Wave> SI::view::Wave::lock() {
	auto model = Wave::model.lock();
	if (!model || model->mayDeleteThis()) deleteThis();
	return model;
}
