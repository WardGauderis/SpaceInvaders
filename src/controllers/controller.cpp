//
// Created by ward on 12/2/19.
//

#include "controller.h"

#include <utility>

SI::controller::Controller::Controller(std::shared_ptr<view::View>  view) : view(std::move(view)) {}
