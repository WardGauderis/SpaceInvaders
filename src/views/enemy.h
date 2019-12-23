//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYVIEW_H
#define SPACEINVADERS_ENEMYVIEW_H

#include "../models/enemy.h"
#include "spaceShip.h"

namespace SI::view {
/**
 * view class for enemies
 */
class Enemy : public SpaceShip
{
public:
        /**
         * construct with correct model and window
         * @param model pointer
         * @param window SFML window
         */
        Enemy(const std::weak_ptr<model::Enemy>& model, const std::shared_ptr<sf::RenderWindow>& window);

        ~Enemy() override = default;
};

} // namespace SI::view

#endif // SPACEINVADERS_ENEMYVIEW_H
