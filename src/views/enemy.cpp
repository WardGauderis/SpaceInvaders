//
// Created by ward on 12/9/19.
//

#include "enemy.h"

SI::view::Enemy::Enemy(const std::weak_ptr<model::Enemy>& model, const std::shared_ptr<sf::RenderWindow>& window)
    : SpaceShip(model, window)
{
        sprite.setFillColor(sf::Color(200, 43, 43));
}
