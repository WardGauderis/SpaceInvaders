//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYVIEW_H
#define SPACEINVADERS_ENTITYVIEW_H

#include <SFML/Graphics.hpp>

#include "../models/entity.h"
#include "../utils/event.h"
#include "../utils/key.h"
#include "../utils/vector.h"

namespace SI::view {
/**
 * abstract entity view class
 */
class Entity : public utils::Observer
{
public:
        /**
         * default constructor
         */
        Entity();

        /**
         * constructor with window
         * @param window SFML window
         */
        explicit Entity(std::shared_ptr<sf::RenderWindow> window);

        /**
         * abstract function that is called when the view is updated
         */
        virtual void update() = 0;

        /**
         * check if the object may be deleted
         * @return true if it may be deleted
         */
        [[nodiscard]] bool mayDeleteThis() const;

        /**
         * check whether a key is pressed
         * @param key utils::Key
         * @return true if pressed
         */
        static bool isKeyPressed(utils::Key key);

        /**
         * poll for an event that must be handled
         * @param event utils::Event
         * @return whether an event is available
         */
        bool pollEvent(utils::Event& event);

        /**
         * determine in what order the objects must be drawn
         * @return the higher the int, the later the object is updated on screen
         */
        virtual int drawOrder();

        ~Entity() override = default;

protected:
        std::shared_ptr<sf::RenderWindow> window;

        /**
         * indicate that this object may be deleted
         */
        void deleteThis();

        /**
         * center SFML text around a point
         * @param text SFML text
         * @param string text string
         * @param pos point
         */
        static void centerText(sf::Text& text, const std::string& string, utils::Vector pos);

private:
        bool mustDelete;
};

} // namespace SI::view

#endif // SPACEINVADERS_ENTITYVIEW_H
