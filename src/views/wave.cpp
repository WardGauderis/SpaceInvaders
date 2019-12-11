//
// Created by ward on 12/9/19.
//

#include "wave.h"

#include <utility>

SI::view::Wave::Wave(std::weak_ptr<model::Wave> model, const std::shared_ptr<sf::RenderWindow>& window) : Entity(
		window), model(std::move(model)) {}

void SI::view::Wave::notify() {
	lock();
}

void SI::view::Wave::update() {

}

std::shared_ptr<SI::model::Wave> SI::view::Wave::lock() {
	auto model = Wave::model.lock();
	if (!model || model->mayDeleteThis()) deleteThis();
	return model;
}