//
// Created by ward on 12/19/19.
//

#ifndef SPACEINVADERS_EXPLOSIONVIEW_H
#define SPACEINVADERS_EXPLOSIONVIEW_H

#include "../models/explosion.h"
#include "entity.h"

namespace SI::view {
/**
 * view class for the explosion model
 */
class Explosion : public Entity
{
public:
        /**
         * construct with the correct model and window
         * @param model pointer
         * @param window SFML window
         */
        Explosion(std::weak_ptr<model::Explosion> model, const std::shared_ptr<sf::RenderWindow>& window);

        /**
         * notify the view when the explosion model has changed
         */
        void notify() final;

        /**
         * function that is called when the view is updated
         */
        void update() final;

        /**
         * determine in what order the objects must be drawn
         * @return the higher the int, the later the object is updated on screen
         */
        int drawOrder() final;

        ~Explosion() final = default;

private:
        const std::weak_ptr<model::Explosion> model;
        sf::RectangleShape sprite;
        /**
         * check whether the model pointer is still present
         * @return shared pointer to the model
         */
        std::shared_ptr<model::Explosion> lock();
};

} // namespace SI::view

#endif // SPACEINVADERS_EXPLOSIONVIEW_H
