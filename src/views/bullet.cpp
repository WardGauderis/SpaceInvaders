//
// Created by ward on 12/8/19.
//

#include "bullet.h"

SI::view::Bullet::Bullet(const std::weak_ptr<model::Bullet>& model,
                         const std::shared_ptr<sf::RenderWindow>& window) : PhysicalEntity(model, window) {
	auto m = lock();
	if (std::dynamic_pointer_cast<model::Bullet>(m)->getTeam()) {
		sprite.setFillColor(sf::Color(54, 182, 250));
	} else {
		sprite.setFillColor(sf::Color(250, 54, 54));
	}
}