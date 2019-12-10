//
// Created by ward on 12/8/19.
//

#include "bullet.h"

SI::model::Bullet::Bullet() {
	size = {0.2f, 0.3f};
	drag = 1.0f;
}

void SI::model::Bullet::onWallCollision(utils::Vector wall) {
	if(wall.y == 3){
		deleteThis();
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}
