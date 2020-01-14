//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_PHYSICALENTITYVIEW_H
#define SPACEINVADERS_PHYSICALENTITYVIEW_H

#include "../models/physicalEntity.h"
#include "entity.h"

/**
 * Space Invaders namespace for views
 */
namespace SI::view {
/**
 * view class for physical entities
 */
class PhysicalEntity : public Entity
{
public:
        /**
         * construct with the correct model and window
         * @param model pointer
         * @param window SFML window
         */
        PhysicalEntity(std::weak_ptr<model::PhysicalEntity> model, const std::shared_ptr<sf::RenderWindow>& window);

        /**
         * function that is called when the model changes
         */
        void notify() override;

        /**
         * function that is called when the view is updated
         */
        void update() override;

        ~PhysicalEntity() override = default;

protected:
        const std::weak_ptr<model::PhysicalEntity> model;
        sf::RectangleShape sprite;

        /**
         * check whether the model pointer is still present, otherwise delete this
         * @return shared pointer to model
         */
        std::shared_ptr<model::PhysicalEntity> lock();
};

} // namespace SI::view

#endif // SPACEINVADERS_PHYSICALENTITYVIEW_H
