//
// Created by ward on 12/24/19.
//

#ifndef SPACEINVADERS_GHOSTMODEL_H
#define SPACEINVADERS_GHOSTMODEL_H

#include "../../utils/stopWatch.h"
#include "../enemy.h"

/**
 * Space Invaders namespace for models
 */
namespace SI::model {
/**
 * model class for the type of enemy ghost
 */
class Ghost : public Enemy
{
public:
        /**
         * default constructor
         */
        Ghost();

        /**
         * function that is called when the model is updated
         * update the position and state
         */
        void update() final;

        /**
         * handle collision
         * only collide with bullets if visible
         * @param entity entity to check
         * @return true if it collides
         */
        bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity) final;

        /**
         * try to shoot a bullet
         * only possible if visible
         * @return success
         */
        bool shoot() final;

        /**
         * get the opacity of the ghost
         * @return uint8_t
         */
        [[nodiscard]] uint8_t getOpacity() const;

        ~Ghost() final = default;

private:
        /**
         * state of ghost
         */
        enum class Visibility
        {
                visible,
                invisible,
                appearing,
                disappearing
        };

        Visibility state;
        utils::Timer timer;
        static const unsigned int stable = 120;
        static const unsigned int transition = 45;
};

} // namespace SI::model

#endif // SPACEINVADERS_GHOSTMODEL_H
