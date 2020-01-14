//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_PLAYERCONTROLLER_H
#define SPACEINVADERS_PLAYERCONTROLLER_H

#include "../views/player.h"
#include "physicalEntity.h"

/**
 * Space Invaders namespace for controllers
 */
namespace SI::controller {
/**
 * controller class for the player
 */
class Player : public PhysicalEntity
{
public:
        /**
         * construct with correct model and view
         * @param model pointer
         * @param view pointer
         */
        Player(const std::weak_ptr<model::Player>& model, const std::weak_ptr<view::Player>& view);
        /**
         * update the player with user input
         */
        void update() final;

        ~Player() final = default;
};

} // namespace SI::controller

#endif // SPACEINVADERS_PLAYERCONTROLLER_H
