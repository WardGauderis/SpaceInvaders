//
// Created by ward on 12/9/19.
//

#include "enemy.h"
#include "bullet.h"
#include "player.h"

std::default_random_engine SI::model::Enemy::generator = std::default_random_engine((std::random_device()) ());


SI::model::Enemy::Enemy() : SpaceShip(1, {0.5, 0.5}, {0, 0}, {0.02f, 0}, 1), distribution(1, 15) {}

void SI::model::Enemy::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	if (auto bullet = std::dynamic_pointer_cast<Bullet>(entity)) {
		if (bullet->getTeam() && loseLive() == 0) deleteThis();
	} else if (typeid(*entity) == typeid(Player)) {
		loseLive();
	} else {
		PhysicalEntity::onCollision(entity);
	}
}

bool SI::model::Enemy::shoot() {
	if (distribution(generator) == 1) return SpaceShip::shoot(false);
	return false;
}

unsigned int SI::model::Enemy::getShootChance() const {
	return static_cast<unsigned int>(distribution.max());
}

void SI::model::Enemy::setShootChance(const unsigned int chance) {
	distribution = std::uniform_int_distribution<>(1, static_cast<int>(chance));
}

void SI::model::Enemy::onWallCollision(utils::Vector wall) {
	if (wall.y == 3) {
		wall.y = 0;
	} else if (wall.y == -3) {
		deleteThis();
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}