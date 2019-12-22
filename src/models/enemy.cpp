//
// Created by ward on 12/9/19.
//

#include "enemy.h"
#include "bullet.h"
#include "player.h"

bool SI::model::Enemy::hitGround = false;

SI::model::Enemy::Enemy() : SpaceShip(1, {0.5, 0.5}, {0, 0}, {0.015f, 0}, 1, 0.05f, false), value(10) {
	setCoolDown(90);
}

bool SI::model::Enemy::shoot() {
	if (detectWallCollision().y == 3) return false;
	if (distribution(generator()) == 1) return SpaceShip::shoot(false);
	return false;
}

unsigned int SI::model::Enemy::getShootChance() const {
	return static_cast<unsigned int>(distribution.max());
}

void SI::model::Enemy::setCoolDown(const unsigned int coolDown) {
	if (coolDown < 0) throw std::runtime_error("cooldown must be positive");
	distribution = std::uniform_int_distribution<int>(1, static_cast<int>(coolDown));
}

int SI::model::Enemy::getValue() const {
	return value;
}

void SI::model::Enemy::setValue(int v) {
	Enemy::value = v;
}

void SI::model::Enemy::deleteThis() {
	Player::addScore(value);
	SI::model::SpaceShip::deleteThis();
}

void SI::model::Enemy::onWallCollision(utils::Vector wall) {
	if (wall.y == 3) {
		wall.y = 0;
	} else if (wall.y == -2.75f) {
		loseLive();
		hitGround = true;
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}

bool SI::model::Enemy::hasHitGround() {
	return hitGround;
}

void SI::model::Enemy::restart() {
	hitGround = false;
}
