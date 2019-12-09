//
// Created by ward on 12/9/19.
//

#include "enemy.h"

SI::controller::Enemy::Enemy(const std::shared_ptr<model::SpaceShip>& model,
                             const std::shared_ptr<view::SpaceShip>& view) : SpaceShip(model, view) {}
