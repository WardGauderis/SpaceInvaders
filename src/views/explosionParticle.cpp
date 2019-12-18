//
// Created by ward on 12/16/19.
//

#include "explosionParticle.h"

SI::view::ExplosionParticle::ExplosionParticle(const std::weak_ptr<model::ExplosionParticle>& model,
                                               const std::shared_ptr<sf::RenderWindow>& window) : PhysicalEntity(model,
                                                                                                                 window) {
	notify();
}

void SI::view::ExplosionParticle::notify() {
	auto timer = std::dynamic_pointer_cast<model::ExplosionParticle>(lock())->getTimer();
	auto opacity = static_cast<uint8_t>(255 * timer.getTime() / timer.getCooldown());
	sprite.setFillColor(sf::Color(240, 129, 73, opacity));
	PhysicalEntity::notify();
}

int SI::view::ExplosionParticle::drawOrder() {
	return -1;
}
