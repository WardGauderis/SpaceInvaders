//
// Created by ward on 12/16/19.
//

#include "explosionParticle.h"

SI::model::ExplosionParticle::ExplosionParticle(const utils::Vector& size, const utils::Vector& position,
                                                const utils::Vector& velocity) : PhysicalEntity(0.99f, size, position,
                                                                                                velocity), timer(180) {
	timer.reset();
}

void SI::model::ExplosionParticle::update() {
	timer.update();
	if (timer.ready()) deleteThis();
	PhysicalEntity::update();
}

void SI::model::ExplosionParticle::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {}

void SI::model::ExplosionParticle::move() {
	velocity -= {0, 0.005f};
	PhysicalEntity::move();
}

void SI::model::ExplosionParticle::onWallCollision(utils::Vector wall) {
	if (static_cast<bool>(wall.x)) {
		velocity.x = -velocity.x * 0.6f;
		auto delta = position.x + size.x / 2 * utils::getSign(wall.x) - wall.x;
		position.x -= 2 * delta * drag;
	}
	if (static_cast<bool>(wall.y)) {
		velocity.y = -velocity.y * 0.6f;
		auto delta = position.y + size.y / 2 * utils::getSign(wall.y) - wall.y;
		position.y -= 2 * delta * drag;
	}
}
