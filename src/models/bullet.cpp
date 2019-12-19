//
// Created by ward on 12/8/19.
//

#include "bullet.h"
#include "player.h"
#include "enemy.h"

SI::model::Bullet::Bullet(const utils::Vector& velocity, bool playerTeam)
		: PhysicalEntity(1, {0.05f, 0.1f}, {0, 0}, velocity), playerTeam(playerTeam) {}

bool SI::model::Bullet::getTeam() const {
	return playerTeam;
}

void SI::model::Bullet::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	if (playerTeam && typeid(*entity) == typeid(Player)) return;
	if (!playerTeam && typeid(*entity) == typeid(Enemy)) return;
	deleteThis();
}

void SI::model::Bullet::onWallCollision(utils::Vector wall) {
	if (std::abs(wall.y) == 3) {
		deleteThis();
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}

