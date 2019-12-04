//
// Created by ward on 11/25/19.
//

#include "entity.h"

SI::controller::Entity::Entity(const std::shared_ptr<view::View>& view, const std::shared_ptr<model::Entity>& model)
		: Controller(view), model(model) {}
