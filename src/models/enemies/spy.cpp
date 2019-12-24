//
// Created by ward on 12/24/19.
//

#include "spy.h"
#include "../bullet.h"

SI::model::Spy::Spy() : state(Visibility::invisible), timer(stable) {
	setValue(20);
	setVelocity({0.02f, 0});
	timer.reset();
}

void SI::model::Spy::update() {
	if (timer.ready()) {
		switch (state) {
			case Visibility::visible:
				state = Visibility::disappearing;
				timer = utils::Timer(transition);
				break;
			case Visibility::invisible:
				state = Visibility::appearing;
				timer = utils::Timer(transition);
				break;
			case Visibility::appearing:
				state = Visibility::visible;
				timer = utils::Timer(stable);
				break;
			case Visibility::disappearing:
				state = Visibility::invisible;
				timer = utils::Timer(stable);
				break;
		}
		timer.reset();
	}
	Enemy::update();
	if (detectWallCollision().y == 3) return;
	timer.update();
}

bool SI::model::Spy::collidesWith(const std::shared_ptr<PhysicalEntity>& entity) {
	if(state != Visibility::visible && std::dynamic_pointer_cast<Bullet>(entity)) {
		return false;
	}
	return PhysicalEntity::collidesWith(entity);
}

bool SI::model::Spy::shoot() {
	if (state != Visibility::visible) return false;
	return Enemy::shoot();
}

uint8_t SI::model::Spy::getOpacity() const {
	uint8_t opacity = 0;
	switch (state) {
		case Visibility::visible:
			opacity = 255;
			break;
		case Visibility::invisible:
			opacity = 0;
			break;
		case Visibility::appearing:
			opacity = (1 - static_cast<float>(timer.getTime()) / transition) * 255;
			break;
		case Visibility::disappearing:
			opacity = (static_cast<float>(timer.getTime()) / transition) * 255;
			break;
	}
	return opacity;
}