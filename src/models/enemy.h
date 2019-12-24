//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYMODEL_H
#define SPACEINVADERS_ENEMYMODEL_H

#include "spaceShip.h"

namespace SI::model {
/**
 * model class for enemies
 */
class Enemy : public SpaceShip
{
public:
        /**
         * default constructor
         */
        Enemy();

        /**
         * try to shoot a bullet
         * @return success
         */
        virtual bool shoot();

        /**
         * get the chance (cooldown) to shoot
         * @return cooldown
         */
        [[nodiscard]] unsigned int getCoolDown() const;

        /**
         * set the chance (cooldown) to shoot
         * @param coolDown int;
         */
        void setCoolDown(int coolDown);

        /**
         * get the value (points)
         * @return value
         */
        [[nodiscard]] int getValue() const;

        /**
         * set the value (points)
         * @param v value
         */
        void setValue(int v);

        /**
         * indicate that this may be deleted
         */
        void deleteThis() final;

        /**
         * returns whether an enemy has yet hit the ground
         * @return true if it has happened;
         */
        static bool hasHitGround();

        /**
         * reset the hasHitGround() function
         */
        static void reset();

        ~Enemy() override = default;

private:
        std::uniform_int_distribution<int> distribution;
        int value;

        static bool hitGround;
        /**
         * handle wall collision
         * @param wall collision position
         */
        void onWallCollision(utils::Vector wall) final;
};

} // namespace SI::model

#endif // SPACEINVADERS_ENEMYMODEL_H
