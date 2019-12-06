//
// Created by ward on 11/25/19.
//

#include "entity.h"

#include <utility>

SI::controller::Entity::Entity(std::shared_ptr<model::Entity>  model, std::shared_ptr<view::Entity>  view)
		: model(std::move(model)), view(std::move(view)) {}
