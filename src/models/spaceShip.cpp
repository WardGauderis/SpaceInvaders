//
// Created by ward on 12/3/19.
//

#include "spaceShip.h"
#include "bullet.h"

SI::model::SpaceShip::SpaceShip(unsigned int lives, unsigned int cooldown) : lives(lives), cooldown(cooldown),
                                                                             timer(0) {}

void SI::model::SpaceShip::update() {
	if (timer != 0) --timer;
	PhysicalEntity::update();
}

unsigned int SI::model::SpaceShip::loseLive() {
	return --lives;
}

bool SI::model::SpaceShip::shoot(bool team) {
	if (timer != 0) return false;
	timer = cooldown;
	auto bullet = std::make_shared<Bullet>(team);
	bullet->setPosition({position.x, position.y + size.y / 2 + bullet->getSize().y / 2});
	bullet->setVelocity(velocity + utils::Vector(0, 0.1f));
	addModel(bullet);
	return true;
}

