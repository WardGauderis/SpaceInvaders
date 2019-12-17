//
// Created by ward on 12/16/19.
//

#include "explosionParticle.h"

SI::view::ExplosionParticle::ExplosionParticle(const std::weak_ptr<model::ExplosionParticle>& model,
                                               const std::shared_ptr<sf::RenderWindow>& window) : PhysicalEntity(model,
                                                                                                                 window) {}

int SI::view::ExplosionParticle::drawOrder() {
	return -1;
}
