//
// Created by ward on 12/9/19.
//

#include "wave.h"

SI::controller::Wave::Wave(std::weak_ptr<model::Wave> model, std::weak_ptr<view::Wave> view) : model(std::move(
		model)), view(std::move(view)) {}

void SI::controller::Wave::update() {
	lock();
}

std::pair<std::shared_ptr<SI::model::Wave>, std::shared_ptr<SI::view::Wave>> SI::controller::Wave::lock() {
	auto model = Wave::model.lock();
	auto view = Wave::view.lock();
	if (!model || !view || model->mayDeleteThis() || view->mayDeleteThis()) deleteThis();
	return {model, view};
}
