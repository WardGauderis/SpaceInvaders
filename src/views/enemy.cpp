//
// Created by ward on 12/9/19.
//

#include "enemy.h"

SI::view::Enemy::Enemy(const std::shared_ptr<model::PhysicalEntity>& model,
                       const std::shared_ptr<sf::RenderWindow>& window) : SpaceShip(model, window) {}
