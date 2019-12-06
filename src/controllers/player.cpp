//
// Created by ward on 12/3/19.
//

#include "player.h"

void SI::controller::Player::handleInput() {
	const float acc = 0.5;
	if (view->isKeyPressed(utils::Key::up))
		model->addAcceleration({acc, 0});
	if (view->isKeyPressed(utils::Key::down))
		model->addAcceleration({-acc, 0});
	if (view->isKeyPressed(utils::Key::left))
		model->addAcceleration({0, acc});
	if (view->isKeyPressed(utils::Key::right))
		model->addAcceleration({0, -acc});
}

SI::controller::Player::Player(const std::shared_ptr<view::Player>& view, const std::shared_ptr<model::Player>& model)
		: SpaceShip(view, model) {}
