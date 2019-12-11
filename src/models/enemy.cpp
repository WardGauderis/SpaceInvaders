//
// Created by ward on 12/9/19.
//

#include "enemy.h"

SI::model::Enemy::Enemy() {
	size = {0.5, 0.5};
	drag = 1.0f;
}

void SI::model::Enemy::onWallCollision(utils::Vector wall) {
	if(wall.y == 3){
		wall.y = 0;
	} else if(wall.y == -3) {
		deleteThis();
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}
