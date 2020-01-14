//
// Created by ward on 12/15/19.
//

#ifndef SPACEINVADERS_DISPLAY_H
#define SPACEINVADERS_DISPLAY_H

#include "../models/player.h"
#include "../models/wave.h"
#include "entity.h"

/**
 * Space Invaders namespace for views
 */
namespace SI::view {
/**
 * view class that represents the bar with information at the bottom of the screen
 */
class Display : public Entity
{
public:
        /**
         * construct with the correct models an window
         * @param window SFML window
         * @param playerModel pointer
         * @param waveModel pointer
         */
        Display(const std::shared_ptr<sf::RenderWindow>& window, std::weak_ptr<model::Player> playerModel,
                std::weak_ptr<model::Wave> waveModel);

        /**
         * notify the display of changes in the models
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

        ~Display() final = default;

private:
        const std::weak_ptr<model::Player> playerModel;
        const std::weak_ptr<model::Wave> waveModel;

        sf::RectangleShape bar;

        sf::Text lives;
        sf::Text score;
        sf::Text waveNumber;

        /**
         * check whether the model pointers are still present
         * @return shared pointers to models
         */
        std::pair<std::shared_ptr<model::Player>, std::shared_ptr<model::Wave>> lock();
};

} // namespace SI::view

#endif // SPACEINVADERS_DISPLAY_H
