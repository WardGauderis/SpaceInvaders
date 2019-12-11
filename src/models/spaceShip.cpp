//
// Created by ward on 12/3/19.
//

#include "../spaceInvaders.h"

void SI::model::SpaceShip::action() {
	auto bullet = std::make_shared<Bullet>();
	bullet->setPosition(position);
	bullet->setVelocity(velocity + utils::Vector::normalize(velocity) / 20);
	addModel(bullet);
}
