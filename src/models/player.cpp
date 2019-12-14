//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "bullet.h"
#include "enemy.h"

SI::model::Player::Player() : SpaceShip(0.99f, {0.5, 0.5}, {0, -2.5}, {0, 0}, 1000), cooldown(15), timer(0) {}

void SI::model::Player::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	if (auto bullet = std::dynamic_pointer_cast<Bullet>(entity)) {
		if (!bullet->getTeam() && loseLive() == 0) deleteThis();
	} else if (typeid(*entity) == typeid(Enemy)) {
		loseLive();
	}
}

void SI::model::Player::update() {
	if(timer != 0) --timer;
	SpaceShip::update();
}

bool SI::model::Player::shoot() {
	if(timer != 0) return false;
	timer = cooldown;
	return SpaceShip::shoot(true);
}
