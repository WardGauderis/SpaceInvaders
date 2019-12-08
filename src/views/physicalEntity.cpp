//
// Created by ward on 12/8/19.
//

#include "physicalEntity.h"

#include <utility>
#include "../utils/transformation.h"

SI::view::PhysicalEntity::PhysicalEntity(std::shared_ptr<model::PhysicalEntity>  model,
                                         const std::shared_ptr<sf::RenderWindow>& window) : Entity(window),
                                                                                            model(std::move(model)) {}

void SI::view::PhysicalEntity::notify() {
	sprite.setSize(utils::Transformation::get().convertDistance<float>(model->getSize()));
	sprite.setPosition(utils::Transformation::get().convertPoint<float>(model->getPosition() - model->getSize() / 2));
}

void SI::view::PhysicalEntity::update() {
	window->draw(sprite);
}
