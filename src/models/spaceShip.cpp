//
// Created by ward on 12/3/19.
//

#include "spaceShip.h"
#include "bullet.h"
#include "explosion.h"

SI::model::SpaceShip::SpaceShip(const float drag, const utils::Vector& size, const utils::Vector& position,
                                const utils::Vector& velocity, const unsigned int lives, const float bulletSpeed,
                                bool team)
    : PhysicalEntity(drag, size, position, velocity, team), lives(lives), bulletSpeed(0)
{
        setBulletSpeed(bulletSpeed);
}

void SI::model::SpaceShip::onCollision(const std::shared_ptr<PhysicalEntity>& entity)
{
        if (std::dynamic_pointer_cast<Bullet>(entity)) {
                if (entity->getTeam() == getTeam())
                        return;
        } else if (entity->getTeam() == getTeam()) {
                PhysicalEntity::onCollision(entity);
                return;
        }
        loseLive();
}

unsigned int SI::model::SpaceShip::getLives() const { return lives; }

void SI::model::SpaceShip::setLives(const unsigned int amount)
{
        if (amount <= 0)
                throw std::runtime_error("lives must be more than 0");
        SpaceShip::lives = amount;
}

unsigned int SI::model::SpaceShip::loseLive()
{
        addModel(std::make_shared<Explosion>(*this));
        if (--lives == 0)
                deleteThis();
        notifyObservers();
        return lives;
}

float SI::model::SpaceShip::getBulletSpeed() const { return bulletSpeed; }

void SI::model::SpaceShip::setBulletSpeed(float speed)
{
        if (speed < 0)
                throw std::runtime_error("bullet speed must be greater than 0");
        SpaceShip::bulletSpeed = speed;
}

bool SI::model::SpaceShip::shoot(const bool team)
{
        auto bullet = std::make_shared<Bullet>(velocity + utils::Vector(0, (team ? 1.0f : -1.0f) * bulletSpeed), team);
        bullet->setPosition({position.x, position.y + (team ? 1.0f : -1.0f) * (size.y / 2 - bullet->getSize().y / 2)});
        addModel(bullet);
        return true;
}
