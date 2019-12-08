//
// Created by ward on 12/3/19.
//

#include "player.h"
#include "../spaceInvaders.h"
#include "../entities.h"

SI::model::Player::Player() {
	size = {1, 1};
}

void SI::model::Player::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {

}

void SI::model::Player::action(SI::SpaceInvaders& game) {
	auto bullet = game.addEntity<SI::Bullet>();
	bullet->setSize({0.2f, 0.5f});
	bullet->setPosition(position);
	bullet->setVelocity(velocity);
}
