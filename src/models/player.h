//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERMODEL_H
#define SPACEINVADERS_PLAYERMODEL_H

#include "../utils/stopWatch.h"
#include "spaceShip.h"

/**
 * Space Invaders namespace for models
 */
namespace SI::model {
/**
 * model for the player
 */
class Player : public SpaceShip
{
public:
        /**
         * default constructor
         */
        Player();

        /**
         * function that is called when the model is update every tick
         * move the player
         */
        void update() final;

        /**
         * lose a live and make an explosion
         * @return lives
         */
        unsigned int loseLive() final;

        /**
         * try to shoot a bullet
         * @return success
         */
        bool shoot();

        /**
         * get the player score
         * @return score
         */
        static int getScore();

        /**
         * add points to the player score
         * @param points points
         */
        static void addScore(int points);

        /**
         * reset the player score to 0;
         */
        static void resetScore();

        ~Player() final = default;

private:
        utils::Timer timer;
        static int score;
};

} // namespace SI::model

#endif // SPACEINVADERS_PLAYERMODEL_H
