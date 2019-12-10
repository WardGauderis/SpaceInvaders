//
// Created by ward on 12/8/19.
//

#include "physicalEntity.h"

SI::controller::PhysicalEntity::PhysicalEntity(std::weak_ptr<model::PhysicalEntity> model,
                                               std::weak_ptr<view::PhysicalEntity> view) : model(std::move(model)),
                                                                                           view(std::move(view)) {}

void SI::controller::PhysicalEntity::update(SI::SpaceInvaders& game) {
	lock();
}

std::pair<std::shared_ptr<SI::model::PhysicalEntity>, std::shared_ptr<SI::view::PhysicalEntity>>
SI::controller::PhysicalEntity::lock() {
	auto model = PhysicalEntity::model.lock();
	auto view = PhysicalEntity::view.lock();
	if(!model || !view || model->mayDeleteThis() || view->mayDeleteThis()) deleteThis();
	return {model, view};
}
