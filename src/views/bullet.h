//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_BULLETVIEW_H
#define SPACEINVADERS_BULLETVIEW_H

#include "../models/bullet.h"
#include "physicalEntity.h"

/**
 * Space Invaders namespace for views
 */
namespace SI::view {
/**
 * view class for bullets
 */
class Bullet : public PhysicalEntity
{
public:
        /**
         * construct with correct model and window
         * @param model pointer
         * @param window SFML window
         */
        Bullet(const std::weak_ptr<model::Bullet>& model, const std::shared_ptr<sf::RenderWindow>& window);

        /**
         * notify the view for updates in the model
         */
        void notify() override;

        ~Bullet() final = default;
};

} // namespace SI::view

#endif // SPACEINVADERS_BULLETVIEW_H
