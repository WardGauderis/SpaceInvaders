//
// Created by ward on 12/3/19.
//

#include "player.h"

SI::controller::Player::Player(const std::weak_ptr<model::Player>& model, const std::weak_ptr<view::Player>& view)
		: PhysicalEntity(model, view) {}

void SI::controller::Player::update() {
	auto[model, view] = lock();
	if (mayDeleteThis()) return;

	const float acc = 0.005f;
//	if (view->isKeyPressed(utils::Key::up))
//		model->addVelocity({0, acc});
//	if (view->isKeyPressed(utils::Key::down))
//		model->addVelocity({0, -acc});
	if (view->isKeyPressed(utils::Key::left))
		model->addVelocity({-acc, 0});
	if (view->isKeyPressed(utils::Key::right))
		model->addVelocity({acc, 0});
	if (view->isKeyPressed(utils::Key::space))
		std::dynamic_pointer_cast<model::Player>(model)->shoot();
}
