//
// Created by ward on 12/9/19.
//

#include "enemy.h"

SI::controller::Enemy::Enemy(const std::weak_ptr<model::Enemy>& model, const std::weak_ptr<view::Enemy>& view)
		: SpaceShip(model, view) {}
