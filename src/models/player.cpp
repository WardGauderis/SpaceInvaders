//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "bullet.h"
#include "enemy.h"

SI::model::Player::Player() : SpaceShip(0.9f, {0.5, 0.5}, {0, -2.5}, {0, 0}, 3, 0.05f), timer(20) {}

void SI::model::Player::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	if (auto bullet = std::dynamic_pointer_cast<Bullet>(entity)) {
		if (!bullet->getTeam() && loseLive() == 0) deleteThis();
	} else if (typeid(*entity) == typeid(Enemy)) {
		loseLive();
	}
}

void SI::model::Player::update() {
	timer.update();
	SpaceShip::update();
}

bool SI::model::Player::shoot() {
	if(!timer.ready()) return false;
	return SpaceShip::shoot(true);
}
