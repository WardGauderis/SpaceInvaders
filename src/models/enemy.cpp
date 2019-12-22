//
// Created by ward on 12/9/19.
//

#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "explosion.h"

int SI::model::Enemy::score = 0;

SI::model::Enemy::Enemy() : SpaceShip(1, {0.5, 0.5}, {0, 0}, {0.015f, 0}, 1, 0.05f, false), value(10) {
	setCooldown(90);
}

bool SI::model::Enemy::shoot() {
	if (detectWallCollision().y == 3) return false;
	if (distribution(generator) == 1) return SpaceShip::shoot(false);
	return false;
}

unsigned int SI::model::Enemy::getShootChance() const {
	return static_cast<unsigned int>(distribution.max());
}

void SI::model::Enemy::setCooldown(const unsigned int cooldown) {
	if (cooldown < 0) throw std::runtime_error("cooldown must be positive");
	distribution = std::uniform_int_distribution<int>(1, static_cast<int>(cooldown));
}

int SI::model::Enemy::getValue() const {
	return value;
}

void SI::model::Enemy::setValue(int value) {
	Enemy::value = value;
}

int SI::model::Enemy::getScore() {
	return score;
}

void SI::model::Enemy::onWallCollision(utils::Vector wall) {
	if (wall.y == 3) {
		wall.y = 0;
	} else if (wall.y == -2.75f) {
		deleteThis();
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}

void SI::model::Enemy::deleteThis() {
	score += value;
	SI::model::SpaceShip::deleteThis();
}
