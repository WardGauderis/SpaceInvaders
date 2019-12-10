//
// Created by ward on 12/8/19.
//

#include "bullet.h"

SI::view::Bullet::Bullet(const std::weak_ptr<model::Bullet>& model,
                         const std::shared_ptr<sf::RenderWindow>& window) : PhysicalEntity(model, window) {
	sprite.setFillColor(sf::Color::Red);
}