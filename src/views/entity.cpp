//
// Created by ward on 11/25/19.
//

#include "entity.h"
#include "../utils/transformation.h"

SI::view::Entity::Entity() : Entity(nullptr) {}

SI::view::Entity::Entity(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)), mustDelete(false) {}

bool SI::view::Entity::mayDeleteThis() const { return mustDelete; }

bool SI::view::Entity::isKeyPressed(utils::Key key)
{
        bool value = false;
        switch (key) {
        case utils::Key::up:
                value = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z);
                break;
        case utils::Key::down:
                value = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
                break;
        case utils::Key::left:
                value = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
                break;
        case utils::Key::right:
                value = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
                break;
        case utils::Key::space:
                value = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
                break;
        case utils::Key::escape:
                value = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
                break;
        case utils::Key::enter:
                value = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
                break;
        }
        return value;
}

bool SI::view::Entity::pollEvent(utils::Event& event)
{
        sf::Event sfEvent{};
        bool moreEvents;
        bool goodEvent = true;

        do {
                moreEvents = window->pollEvent(sfEvent);
                if (!moreEvents)
                        return moreEvents;
                switch (sfEvent.type) {
                case sf::Event::Closed:
                        event.type = utils::Event::closed;
                        break;
                case sf::Event::KeyPressed:
                        event.type = utils::Event::keyPressed;
                        if (sfEvent.key.code == sf::Keyboard::Key::Escape)
                                event.key = utils::Key::escape;
                        else if (sfEvent.key.code == sf::Keyboard::Return)
                                event.key = utils::Key::enter;
                        break;
                default:
                        goodEvent = false;
                }
        } while (!goodEvent);

        return moreEvents;
}

int SI::view::Entity::drawOrder() { return 0; }

void SI::view::Entity::deleteThis() { mustDelete = true; }

void SI::view::Entity::centerText(sf::Text& text, const std::string& string, const utils::Vector pos)
{
        text.setString(string);
        auto textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(utils::Transformation::get().convertPoint<float>(pos));
}
