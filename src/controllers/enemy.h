//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_ENEMYCONTROLLER_H
#define SPACEINVADERS_ENEMYCONTROLLER_H

#include "../views/enemy.h"
#include "physicalEntity.h"

namespace SI::controller {
/**
 * controller class for enemies
 */
class Enemy : public PhysicalEntity
{
public:
        /**
         * construct with correct model and view
         * @param model pointer
         * @param view pointer
         */
        Enemy(const std::weak_ptr<model::Enemy>& model, const std::weak_ptr<view::Enemy>& view);

        /**
         * update the enemy 'AI' and try to shoot
         */
        void update() final;

        ~Enemy() final = default;
};

} // namespace SI::controller

#endif // SPACEINVADERS_ENEMYCONTROLLER_H
