//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "bullet.h"
#include "enemy.h"

SI::model::Player::Player(): SpaceShip(3) {
	size = {0.5, 0.5};
	drag = 0.99f;
	position = {0, -2.5};
}

void SI::model::Player::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	if (auto bullet = std::dynamic_pointer_cast<Bullet>(entity)) {
		if (!bullet->getTeam() && loseLive() == 0) deleteThis();
	} else if (typeid(*entity) == typeid(Enemy)) {
		if (loseLive() == 0) deleteThis();
	}
}
