//
// Created by ward on 12/8/19.
//

#include "physicalEntity.h"
#include "../utils/transformation.h"

SI::view::PhysicalEntity::PhysicalEntity(std::weak_ptr<model::PhysicalEntity> model,
                                         const std::shared_ptr<sf::RenderWindow>& window) : Entity(window),
                                                                                            model(std::move(model)) {}

void SI::view::PhysicalEntity::notify() {
	auto model = lock();
	if (mayDeleteThis()) return;
	sprite.setSize(utils::Transformation::get().convertDistance<float>(model->getSize()));
	sprite.setPosition(utils::Transformation::get().convertPoint<float>(model->getPosition() - model->getSize() / 2));
}

void SI::view::PhysicalEntity::update() {
	window->draw(sprite);
}

std::shared_ptr<SI::model::PhysicalEntity> SI::view::PhysicalEntity::lock() {
	auto model = PhysicalEntity::model.lock();
	if (!model || model->mayDeleteThis()) deleteThis();
	return model;
}
