//
// Created by ward on 12/9/19.
//

#include "wave.h"
#include "../utils/transformation.h"
#include "../utils/assets.h"

SI::view::Wave::Wave(std::weak_ptr<model::Wave> model, const std::shared_ptr<sf::RenderWindow>& window) : Entity(
		window), model(std::move(model)) {
	title.setFont(*utils::Assets::get().getBold());
	auto size = utils::Transformation::get().convertDistance<unsigned int>({0.25f, 0}).x;
	title.setCharacterSize(size);

	notify();
}

void SI::view::Wave::notify() {
	auto m = lock();
	if (mayDeleteThis()) return;
	centerText(title, m->getTitle(), {0, 0.66f});
}

void SI::view::Wave::update() {
	auto m = lock();
	if (mayDeleteThis()) return;
	title.setFillColor(sf::Color(245, 231, 222, m->getOpacity()));
	window->draw(title);
}

int SI::view::Wave::drawOrder() {
	return -1;
}

std::shared_ptr<SI::model::Wave> SI::view::Wave::lock() {
	auto m = model.lock();
	if (!m || m->mayDeleteThis()) deleteThis();
	return m;
}
