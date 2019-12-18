//
// Created by ward on 12/9/19.
//

#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "explosionParticle.h"

std::default_random_engine SI::model::Enemy::generator = std::default_random_engine((std::random_device()) ());
int SI::model::Enemy::score = 0;

SI::model::Enemy::Enemy() : SpaceShip(1, {0.5, 0.5}, {0, 0}, {0.015f, 0}, 1, 0.05f), value(10) {
	setCooldown(90);
}

void SI::model::Enemy::onCollision(const std::shared_ptr<PhysicalEntity>& entity) {
	if (auto bullet = std::dynamic_pointer_cast<Bullet>(entity)) {
		if (bullet->getTeam() && loseLive() == 0) deleteThis();
	} else if (typeid(*entity) == typeid(Player)) {
		loseLive();
	} else {
		PhysicalEntity::onCollision(entity);
	}
}

bool SI::model::Enemy::shoot() {
	if (detectWallCollision().y == 3) return false;
	if (distribution(generator) == 1) return SpaceShip::shoot(false);
	return false;
}

unsigned int SI::model::Enemy::getShootChance() const {
	return static_cast<unsigned int>(distribution.max());
}

void SI::model::Enemy::setCooldown(const unsigned int cooldown) {
	if (cooldown < 0) throw std::runtime_error("cooldown must be positive");
	distribution = std::uniform_int_distribution<>(1, static_cast<int>(cooldown));
}

int SI::model::Enemy::getValue() const {
	return value;
}

void SI::model::Enemy::setValue(int value) {
	Enemy::value = value;
}

int SI::model::Enemy::getScore() {
	return score;
}

void SI::model::Enemy::onWallCollision(utils::Vector wall) {
	if (wall.y == 3) {
		wall.y = 0;
	} else if (wall.y == -3) {
		deleteThis();
		return;
	}
	PhysicalEntity::onWallCollision(wall);
}

void SI::model::Enemy::deleteThis() {
	std::normal_distribution<> a(0, 0.002);
	score += value;
	float width = size.x / 5;
	float height = size.y / 5;
	for (int x = 0; x < 5; ++x) {
		for (int y = 0; y < 5; ++y) {
			auto pos = position + utils::Vector(width * (x - 2.0f), height * (y - 2.0f));
			utils::Vector random(static_cast<float>(a(generator)), static_cast<float>(a(generator)));
			auto vel = velocity + (pos - position) * 0.05f + random;
			addModel(std::make_shared<ExplosionParticle>(utils::Vector{width, height}, pos, vel));
		}
	}
	SI::model::PhysicalEntity::deleteThis();
}
