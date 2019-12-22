//
// Created by ward on 12/19/19.
//

#include "explosion.h"

float SI::model::Explosion::ExplosionParticle::drag = 0.99f;

std::normal_distribution<float> SI::model::Explosion::distribution = std::normal_distribution<float>(0, 0.005f);
std::normal_distribution<float> SI::model::Explosion::ExplosionParticle::distribution = std::normal_distribution<float>(0.5f, 0.2f);

SI::model::Explosion::ExplosionParticle::ExplosionParticle(utils::Vector position, utils::Vector velocity) :
		position(position), velocity(velocity) {}

const utils::Vector& SI::model::Explosion::ExplosionParticle::getPosition() const {
	return position;
}

void SI::model::Explosion::ExplosionParticle::update(const utils::Vector size) {
	velocity -= {0, 0.001f};
	position += velocity;
	velocity *= drag;
	if (auto vector = detectWallCollision(size))
		onWallCollision(vector, size);
}

utils::Vector SI::model::Explosion::ExplosionParticle::detectWallCollision(const utils::Vector size) const {
	utils::Vector wall;
	if (position.x + size.x / 2 > 4) wall.x = 4;
	else if (position.x - size.x / 2 < -4) wall.x = -4;
	if (position.y + size.y / 2 > 3) wall.y = 3;
	else if (position.y - size.y / 2 < -2.75f) wall.y = -2.75f;
	return wall;
}

void SI::model::Explosion::ExplosionParticle::onWallCollision(const utils::Vector wall, const utils::Vector size) {
	if (static_cast<bool>(wall.x)) {
		velocity.x = -velocity.x * static_cast<float>(distribution(generator));
		auto delta = position.x + size.x / 2 * utils::getSign(wall.x) - wall.x;
		position.x -= 2 * delta * 0.99f;
	}
	if (static_cast<bool>(wall.y)) {
		velocity.y = -velocity.y * static_cast<float>(distribution(generator)) ;
		auto delta = position.y + size.y / 2 * utils::getSign(wall.y) - wall.y;
		position.y -= 2 * delta * drag;
	}
}

SI::model::Explosion::Explosion(const PhysicalEntity& origin) : timer(180), team(origin.getTeam()) {
	timer.reset();

	size = {0.05f, 0.05f};
	auto times = origin.getSize() / size;
	for (int x = 0; x < std::ceil(times.x); ++x) {
		for (int y = 0; y < std::ceil(times.y); ++y) {
			auto position = origin.getPosition() - origin.getSize() / 2 + size +
			                utils::Vector(size.x * static_cast<float>(x), size.y * static_cast<float>(y));
			utils::Vector random(static_cast<float>(distribution(generator)),
			                     static_cast<float>(distribution(generator)));
			auto velocity = origin.getVelocity() + (position - origin.getPosition()) * 0.07f + random;
			particles.emplace_back(position, velocity);
		}
	}
}

void SI::model::Explosion::update() {
	timer.update();
	if (timer.ready()) deleteThis();
	for (auto& particle: particles) {
		particle.update(size);
	}
	notifyObservers();
}

const utils::Vector& SI::model::Explosion::getSize() const {
	return size;
}

const utils::Timer& SI::model::Explosion::getTimer() const {
	return timer;
}

bool SI::model::Explosion::getTeam() const {
	return team;
}

const std::vector<SI::model::Explosion::ExplosionParticle>& SI::model::Explosion::getParticles() const {
	return particles;
}
