//
// Created by ward on 12/8/19.
//

#include "bullet.h"
#include "player.h"
#include "enemy.h"

SI::model::Bullet::Bullet(const utils::Vector& velocity, bool team)
		: PhysicalEntity(1, {0.05f, 0.1f}, {0, 0}, velocity, team) {}

void SI::model::Bullet::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	if (team && std::dynamic_pointer_cast<Player>(entity)) return;
	if (!team && std::dynamic_pointer_cast<Enemy>(entity)) return;
	deleteThis();
}

void SI::model::Bullet::onWallCollision(utils::Vector wall) {
	if (wall.y == 3 || wall.y == -2.75f) {
		deleteThis();
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}

