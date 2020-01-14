//
// Created by ward on 12/24/19.
//

#ifndef SPACEINVADERS_GHOSTVIEW_H
#define SPACEINVADERS_GHOSTVIEW_H

#include "../../models/enemies/ghost.h"
#include "../enemy.h"

/**
 * Space Invaders namespace for views
 */
namespace SI::view {

class Ghost : public Enemy
{
public:
        /**
         * construct with correct model and window
         * @param model pointer
         * @param window SFML window
         */
        Ghost(const std::weak_ptr<model::Ghost>& model, const std::shared_ptr<sf::RenderWindow>& window);

        void notify() final;

        ~Ghost() final = default;
};

} // namespace SI::view

#endif // SPACEINVADERS_GHOSTVIEW_H
