//
// Created by ward on 12/24/19.
//

#include "spy.h"
#include "../../utils/transformation.h"
#include "../../utils/assets.h"

SI::view::Spy::Spy(const std::weak_ptr<model::Spy>& model, const std::shared_ptr<sf::RenderWindow>& window) : Enemy(
		model, window, utils::Assets::get().getSpy()) {}


void SI::view::Spy::notify() {
	auto m = lock();
	if (mayDeleteThis()) return;

	auto opacity = std::dynamic_pointer_cast<model::Spy>(m)->getOpacity();
	sign.setFillColor(sf::Color(255, 255, 255, opacity));
	auto color = sprite.getFillColor();
	color.a = opacity;
	sprite.setFillColor(color);
	Enemy::notify();
}