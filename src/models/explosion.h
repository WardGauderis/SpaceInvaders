//
// Created by ward on 12/19/19.
//

#ifndef SPACEINVADERS_EXPLOSIONMODEL_H
#define SPACEINVADERS_EXPLOSIONMODEL_H

#include "../utils/stopWatch.h"
#include "physicalEntity.h"

/**
 * Space Invaders namespace for models
 */
namespace SI::model {
/**
 * model class for explosions
 */
class Explosion : public Entity
{
public:
        /**
         * class for a particle in an explosion
         */
        class ExplosionParticle
        {
        public:
                /**
                 * construct with position and velocity
                 * @param position vector
                 * @param velocity vector
                 */
                ExplosionParticle(utils::Vector position, utils::Vector velocity);

                /**
                 * get particle position
                 * @return position
                 */
                [[nodiscard]] const utils::Vector& getPosition() const;

                /**
                 * update the particle position every tick
                 */
                void update();

                /**
                 * get the static variable size in an exception safe way
                 * @return explosion particle size
                 */
                static const utils::Vector& size();

        private:
                utils::Vector position;
                utils::Vector velocity;
                static float drag;

                /**
                 * get an exception safe static normal distribution
                 * @return normal distribution
                 */
                static std::normal_distribution<float>& distribution();

                /**
                 * detect collision with the walls of the window
                 * @return collision position
                 */
                [[nodiscard]] utils::Vector detectWallCollision() const;

                /**
                 * handle wall collision
                 * @param wall collision position
                 */
                void onWallCollision(utils::Vector wall);
        };

        /**
         * constructor with origin entity
         * @param origin entity
         */
        explicit Explosion(const PhysicalEntity& origin);

        /**
         * function that is called when the model is updated every tick
         * move and adjust opacity
         */
        void update() final;

        /**
         * get the timer
         * @return timer
         */
        [[nodiscard]] const utils::Timer& getTimer() const;

        /**
         * get the team
         * @return true if friendly
         */
        [[nodiscard]] bool getTeam() const;

        /**
         * get all the explosion particles
         * @return vector of particles
         */
        [[nodiscard]] const std::vector<ExplosionParticle>& getParticles() const;

        ~Explosion() final = default;

private:
        std::vector<ExplosionParticle> particles;
        utils::Timer timer;
        const bool team;
        /**
         * get an exception safe static normal distribution
         * @return normal distribution
         */
        static std::normal_distribution<float>& distribution();
};

} // namespace SI::model

#endif // SPACEINVADERS_EXPLOSIONMODEL_H
