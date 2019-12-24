//
// Created by ward on 12/2/19.
//

#include "spaceShip.h"
#include "../utils/transformation.h"

SI::view::SpaceShip::SpaceShip(const std::weak_ptr<model::SpaceShip>& model,
                               const std::shared_ptr<sf::RenderWindow>& window)
    : PhysicalEntity(model, window)
{
        auto m = lock();
        if (m->getTeam())
                sprite.setOutlineColor(sf::Color(50, 50, 200, 100));
        else
                sprite.setOutlineColor(sf::Color(200, 50, 50, 100));
        notify();
}

int SI::view::SpaceShip::drawOrder() { return 2; }

void SI::view::SpaceShip::notify()
{
        auto m = lock();
        if (mayDeleteThis())
                return;
        PhysicalEntity::notify();
        sprite.setOutlineThickness(static_cast<float>(std::dynamic_pointer_cast<model::SpaceShip>(m)->getLives()) *
                                   static_cast<float>(utils::Transformation::get().getWidth()) / 600);
}
