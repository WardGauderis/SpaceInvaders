//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "bullet.h"
#include "enemy.h"

SI::model::Player::Player() : SpaceShip(0.9f, {0.5, 0.5}, {0, -2.5}, {0, 0}, 3, 0.05f, true), timer(20) {}

void SI::model::Player::update() {
	timer.update();
	SpaceShip::update();
}

bool SI::model::Player::shoot() {
	if (!timer.ready()) return false;
	return SpaceShip::shoot(true);
}

unsigned int SI::model::Player::loseLive() {
	auto backupVelocity  = velocity;
	addVelocity({0, 0.05f});
	SpaceShip::loseLive();
	velocity = backupVelocity;
	return getLives();
}
