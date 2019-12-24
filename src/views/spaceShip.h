//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_SPACESHIPVIEW_H
#define SPACEINVADERS_SPACESHIPVIEW_H

#include "../models/spaceShip.h"
#include "physicalEntity.h"

namespace SI::view {
/**
 * view class for space ships
 */
class SpaceShip : public PhysicalEntity
{
public:
        /**
         * construct with correct model and window
         * @param model pointer
         * @param window SFML window
         */
        SpaceShip(const std::weak_ptr<model::SpaceShip>& model, const std::shared_ptr<sf::RenderWindow>& window);

        void notify() override;

        /**
         * determine in what order the objects must be drawn
         * @return the higher the int, the later the object is updated on screen
         */
        int drawOrder() override;

        ~SpaceShip() override = default;
};

} // namespace SI::view

#endif // SPACEINVADERS_SPACESHIPVIEW_H
