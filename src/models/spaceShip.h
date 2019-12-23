//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_SPACESHIPMODEL_H
#define SPACEINVADERS_SPACESHIPMODEL_H

#include "physicalEntity.h"

namespace SI::model {
/**
 * model class for space ships
 */
class SpaceShip : public PhysicalEntity
{
public:
        /**
         * constructor with attributes
         * @param drag 'air' resistance
         * @param size vector
         * @param position vector
         * @param velocity vector
         * @param lives unsigned int
         * @param bulletSpeed float
         * @param team true if friendly
         */
        SpaceShip(float drag, const utils::Vector& size, const utils::Vector& position, const utils::Vector& velocity,
                  unsigned int lives, float bulletSpeed, bool team);

        /**
         * handle the collision with entity
         * @param entity collided entity
         */
        void onCollision(const std::shared_ptr<PhysicalEntity>& entity) override;

        /**
         * get the lives of the ship
         * @return lives
         */
        [[nodiscard]] unsigned int getLives() const;

        /**
         * set the live of the ship
         * @param amount new lives
         */
        void setLives(unsigned int amount);

        /**
         * lose a live
         * @return lives
         */
        virtual unsigned int loseLive();

        /**
         * get the bullet speed
         * @return bullet speed
         */
        [[nodiscard]] float getBulletSpeed() const;

        /**
         * set the bullet speed
         * @param speed float
         */
        void setBulletSpeed(float speed);

        ~SpaceShip() override = default;

protected:
        /**
         * shoot a bullet
         * @param team true if friendly
         * @return true
         */
        bool shoot(bool team);

private:
        unsigned int lives;
        float bulletSpeed;
};

} // namespace SI::model

#endif // SPACEINVADERS_SPACESHIPMODEL_H
