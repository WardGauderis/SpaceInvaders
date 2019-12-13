//
// Created by ward on 12/3/19.
//

#include "spaceShip.h"
#include "bullet.h"

SI::model::SpaceShip::SpaceShip(unsigned int lives) : lives(lives) {}

void SI::model::SpaceShip::shoot() {
	auto bullet = std::make_shared<Bullet>(true);
	bullet->setPosition({position.x, position.y + size.y / 2 + bullet->getSize().y / 2});
	bullet->setVelocity(velocity + utils::Vector(0, 0.1f));
	addModel(bullet);
}

unsigned int SI::model::SpaceShip::loseLive() {
	return --lives;
}
