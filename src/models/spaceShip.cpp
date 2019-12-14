//
// Created by ward on 12/3/19.
//

#include "spaceShip.h"
#include "bullet.h"

SI::model::SpaceShip::SpaceShip(const float drag, const utils::Vector& size, const utils::Vector& position,
                                const utils::Vector& velocity, const unsigned int lives) : PhysicalEntity(drag, size,
                                                                                                          position,
                                                                                                          velocity),
                                                                                           lives(lives) {}


void SI::model::SpaceShip::update() {
	PhysicalEntity::update();
}

unsigned int SI::model::SpaceShip::getLives() const {
	return lives;
}

void SI::model::SpaceShip::setLives(const unsigned int lives) {
	SpaceShip::lives = lives;
	if(lives == 0) throw std::runtime_error("lives cannot manually be set to 0");
}

unsigned int SI::model::SpaceShip::loseLive() {
	if(--lives == 0) deleteThis();
	return lives;
}

bool SI::model::SpaceShip::shoot(bool team) {
	auto bullet = std::make_shared<Bullet>(velocity + utils::Vector(0, team ? 0.05f : -0.05f), team);
	bullet->setPosition({position.x, position.y + (team ? 1.0f : -1) * (size.y / 2 + bullet->getSize().y / 2)});
	addModel(bullet);
	return true;
}
