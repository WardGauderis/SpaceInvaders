//
// Created by ward on 12/2/19.
//

#include "controller.h"

#include <utility>

SI::controller::Controller::Controller(std::shared_ptr<model::Model> model, std::shared_ptr<view::View> view) : model(
		std::move(model)), view(std::move(view)) {}
