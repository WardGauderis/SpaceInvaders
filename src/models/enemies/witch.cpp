//
// Created by ward on 12/24/19.
//

#include "witch.h"
#include "../bullet.h"

SI::model::Witch::Witch()
{
        setValue(25);
        setCoolDown(300);
        setVelocity({0.01f, 0});
        setBulletSpeed(0.07f);
        setLives(3);
}

bool SI::model::Witch::collidesWith(const std::shared_ptr<PhysicalEntity>& entity)
{
        if (entity->getTeam())
                if (std::dynamic_pointer_cast<Bullet>(entity)) {
                        if (!Enemy::collidesWith(entity))
                                return false;
                        if (distribution()(generator()) != 0)
                                return true;
                        entity->setVelocity((-entity->getVelocity()).normalize() * getBulletSpeed());
                        entity->setTeam(team);
                        return false;
                }
        return Enemy::collidesWith(entity);
}

std::uniform_int_distribution<int> SI::model::Witch::distribution()
{
        static std::uniform_int_distribution<int> distribution(0, 3);
        return distribution;
}
