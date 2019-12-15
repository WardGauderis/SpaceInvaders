//
// Created by ward on 12/3/19.
//

#include "spaceShip.h"
#include "bullet.h"

SI::model::SpaceShip::SpaceShip(const float drag, const utils::Vector& size, const utils::Vector& position,
                                const utils::Vector& velocity, const unsigned int lives, const float bulletSpeed)
		: PhysicalEntity(drag, size, position, velocity), lives(lives) {
	setBulletSpeed(bulletSpeed);
}


void SI::model::SpaceShip::update() {
	PhysicalEntity::update();
}

unsigned int SI::model::SpaceShip::getLives() const {
	return lives;
}

void SI::model::SpaceShip::setLives(const unsigned int lives) {
	if (lives <= 0) throw std::runtime_error("lives must be more than 0");
	SpaceShip::lives = lives;
}

unsigned int SI::model::SpaceShip::loseLive() {
	if (--lives == 0) deleteThis();
	return lives;
}

float SI::model::SpaceShip::getBulletSpeed() const {
	return bulletSpeed;
}

void SI::model::SpaceShip::setBulletSpeed(float bulletSpeed) {
	if(bulletSpeed < 0) throw std::runtime_error("bullet speed must be greater than 0");
	SpaceShip::bulletSpeed = bulletSpeed;
}

bool SI::model::SpaceShip::shoot(const bool team) {
	auto bullet = std::make_shared<Bullet>(velocity + utils::Vector(0, (team ? 1.0f : -1.0f) * bulletSpeed), team);
	bullet->setPosition({position.x, position.y + (team ? 1.0f : -1.0f) * (size.y / 2 - bullet->getSize().y / 2)});
	addModel(bullet);
	return true;
}