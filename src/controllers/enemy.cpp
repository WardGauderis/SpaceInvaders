//
// Created by ward on 12/9/19.
//

#include "enemy.h"

SI::controller::Enemy::Enemy(const std::weak_ptr<model::Enemy>& model, const std::weak_ptr<view::Enemy>& view)
		: SpaceShip(model, view) {}

void SI::controller::Enemy::update() {
	auto [model, view] = lock();
	if(mayDeleteThis()) return;
	std::dynamic_pointer_cast<model::Enemy>(model)->shoot();
}
