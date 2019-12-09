//
// Created by ward on 12/3/19.
//

#include "../spaceInvaders.h"

void SI::model::SpaceShip::action(SI::SpaceInvaders& game) {
	auto bullet = game.addEntity<SI::Bullet>();
	bullet->setPosition(position);
	bullet->setVelocity(velocity + utils::Vector::normalize(velocity) / 20);
}
