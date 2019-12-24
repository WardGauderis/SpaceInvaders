//
// Created by ward on 12/8/19.
//

#include "physicalEntity.h"
#include "../utils/transformation.h"

SI::view::PhysicalEntity::PhysicalEntity(std::weak_ptr<model::PhysicalEntity> model,
                                         const std::shared_ptr<sf::RenderWindow>& window)
    : Entity(window), model(std::move(model))
{
        sprite.setSize(utils::Transformation::get().convertDistance<float>(lock()->getSize()));
}

void SI::view::PhysicalEntity::notify()
{
        auto m = lock();
        if (mayDeleteThis())
                return;

        sprite.setPosition(utils::Transformation::get().convertPoint<float>(m->getPosition() - m->getSize() / 2.0f));
}

void SI::view::PhysicalEntity::update()
{
        window->draw(sprite);
}

std::shared_ptr<SI::model::PhysicalEntity> SI::view::PhysicalEntity::lock()
{
        auto m = model.lock();
        if (!m || m->mayDeleteThis())
                deleteThis();
        return m;
}