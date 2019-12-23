//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVE_H
#define SPACEINVADERS_WAVE_H

#include "../models/wave.h"
#include "enemy.h"

namespace SI::view {
/**
 * view class for the wave model that draws the wave title
 */
class Wave : public Entity
{
public:
        /**
         * construct with the correct model and window
         * @param model pointer
         * @param window SFML window
         */
        Wave(std::weak_ptr<model::Wave> model, const std::shared_ptr<sf::RenderWindow>& window);

        /**
         * notify the view for update in the model
         */
        void notify() final;

        /**
         * function that is ran when the view is updated
         */
        void update() final;

        /**
         * determine in what order the objects must be drawn
         * @return the higher the int, the later the object is updated on screen
         */
        int drawOrder() final;

        ~Wave() final = default;

private:
        const std::weak_ptr<model::Wave> model;
        sf::Text title;

        /**
         * check whether the model pointer is still present, otherwise delete this
         * @return shared pointer to model
         */
        std::shared_ptr<model::Wave> lock();
};

} // namespace SI::view

#endif // SPACEINVADERS_WAVE_H
