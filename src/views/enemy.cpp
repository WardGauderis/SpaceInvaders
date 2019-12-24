//
// Created by ward on 12/9/19.
//

#include "enemy.h"
#include "../utils/transformation.h"

SI::view::Enemy::Enemy(const std::weak_ptr<model::Enemy>& model, const std::shared_ptr<sf::RenderWindow>& window)
    : SpaceShip(model, window), textured(false)
{
        sprite.setFillColor(sf::Color(200, 43, 43));
}

SI::view::Enemy::Enemy(const std::weak_ptr<model::Enemy>& model, const std::shared_ptr<sf::RenderWindow>& window,
                       const std::shared_ptr<sf::Texture>& texture)
    : Enemy(model, window)
{
        textured = true;
        sign.setTexture(texture.get());
        auto m = lock();
        auto min = std::min(m->getSize().x, m->getSize().y);
        sign.setSize(utils::Transformation::get().convertDistance<float>({min, min}));
}

void SI::view::Enemy::notify()
{
        SpaceShip::notify();
        if (!textured)
                return;

        auto m = lock();
        if (mayDeleteThis())
                return;
        auto min = std::min(m->getSize().x, m->getSize().y);
        sign.setPosition(
            utils::Transformation::get().convertPoint<float>(m->getPosition() - utils::Vector{min, min} / 2.0f));
}

void SI::view::Enemy::update()
{
        SpaceShip::update();
        if (!textured)
                return;
        window->draw(sign);
}
