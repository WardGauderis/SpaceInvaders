//
// Created by ward on 12/3/19.
//

#include "player.h"

SI::controller::Player::Player(const std::shared_ptr<model::Player>& model, const std::shared_ptr<view::Player>& view)
		: SpaceShip(model, view), cooldown(0) {}

void SI::controller::Player::update(SpaceInvaders& game) {
	if (cooldown != 0) --cooldown;

	const float acc = 0.002f;
	if (view->isKeyPressed(utils::Key::up))
		model->addVelocity({0, acc});
	if (view->isKeyPressed(utils::Key::down))
		model->addVelocity({0, -acc});
	if (view->isKeyPressed(utils::Key::left))
		model->addVelocity({-acc, 0});
	if (view->isKeyPressed(utils::Key::right))
		model->addVelocity({acc, 0});
	if (view->isKeyPressed(utils::Key::space))
		if (cooldown == 0) {
			cooldown = 60;
			model->action(game);
		}
}
