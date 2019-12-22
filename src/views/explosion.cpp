//
// Created by ward on 12/19/19.
//

#include "explosion.h"
#include "../utils/transformation.h"

SI::view::Explosion::Explosion(std::weak_ptr<model::Explosion> model, const std::shared_ptr<sf::RenderWindow>& window)
		: Entity(window), model(std::move(model)) {
	sprite.setSize(utils::Transformation::get().convertDistance<float>(lock()->getSize()));
	notify();
}

void SI::view::Explosion::notify() {
	auto model = lock();
	if (mayDeleteThis()) return;
	auto timer = model->getTimer();
	auto opacity = static_cast<uint8_t>(255 * std::pow(static_cast<float>(timer.getTime()) / static_cast<float>(timer.getCooldown()), 3));
	if (model->getTeam()) sprite.setFillColor(sf::Color(59, 200, 200, opacity));
	else sprite.setFillColor(sf::Color(200, 106, 59, opacity));
}

void SI::view::Explosion::update() {
	auto model = lock();
	if (mayDeleteThis()) return;
	for (const auto& particle: model->getParticles()) {
		sprite.setPosition(utils::Transformation::get().convertPoint<float>(particle.getPosition()));
		window->draw(sprite);
	}
}

int SI::view::Explosion::drawOrder() {
	return -2;
}

std::shared_ptr<SI::model::Explosion> SI::view::Explosion::lock() {
	auto model = Explosion::model.lock();
	if (!model || model->mayDeleteThis()) deleteThis();
	return model;
}
