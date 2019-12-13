//
// Created by ward on 12/8/19.
//

#include "bullet.h"
#include "player.h"
#include "enemy.h"

SI::model::Bullet::Bullet(bool playerTeam) : playerTeam(playerTeam) {
	size = {0.05f, 0.1f};
	drag = 1.0f;
}

bool SI::model::Bullet::getTeam() const {
	return playerTeam;
}

void SI::model::Bullet::onCollision(const std::shared_ptr <PhysicalEntity>& entity) {
	if (playerTeam && typeid(*entity) == typeid(Player)) return;
	if (!playerTeam && typeid(*entity) == typeid(Enemy)) return;
	deleteThis();
}

void SI::model::Bullet::onWallCollision(utils::Vector wall) {
	if (wall.y == 3) {
		deleteThis();
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}
