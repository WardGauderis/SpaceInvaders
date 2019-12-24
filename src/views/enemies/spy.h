//
// Created by ward on 12/24/19.
//

#ifndef SPACEINVADERS_SPYVIEW_H
#define SPACEINVADERS_SPYVIEW_H

#include "../../models/enemies/spy.h"
#include "../enemy.h"

namespace SI::view {

class Spy : public Enemy
{
public:
        /**
         * construct with correct model and window
         * @param model pointer
         * @param window SFML window
         */
        Spy(const std::weak_ptr<model::Spy>& model, const std::shared_ptr<sf::RenderWindow>& window);

        void notify() final;

        ~Spy() final = default;
};

} // namespace SI::view

#endif // SPACEINVADERS_SPYVIEW_H
