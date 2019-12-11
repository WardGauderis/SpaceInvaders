//
// Created by ward on 12/9/19.
//

#include "wave.h"

SI::controller::Wave::Wave(std::weak_ptr<model::Wave>  model, std::weak_ptr<view::Wave>  view) : model(std::move(
		model)), view(std::move(view)) {}

void SI::controller::Wave::update() {

}
