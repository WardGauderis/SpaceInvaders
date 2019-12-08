//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "../spaceInvaders.h"
#include "../entities.h"

SI::model::Player::Player() {
	size = {0.5, 0.5};
	drag = 0.99f;
}

void SI::model::Player::action(SI::SpaceInvaders& game) {
	auto bullet = game.addEntity<SI::Bullet>();
	bullet->setPosition(position);
	bullet->setVelocity(velocity + utils::Vector::normalize(velocity) / 10);
}
