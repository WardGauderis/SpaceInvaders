//
// Created by ward on 11/19/19.
//

#include "spaceInvaders.h"
#include "controllers/player.h"
#include "controllers/enemy.h"
#include "views/bullet.h"
#include "views/explosion.h"
#include "views/wave.h"
#include "views/shield.h"

SI::SpaceInvaders::SpaceInvaders() : model(std::make_shared<model::World>()),
                                     view(std::make_shared<view::World>(model)),
                                     controller(std::make_unique<controller::World>(model, view)) {
	model->addObserver(view);
}

void SI::SpaceInvaders::eventLoop() {
	while (controller->isRunning()) {
		while (utils::StopWatch::get().updateModel()) {
			updateController();
			updateModel();
		}
		if (utils::StopWatch::get().updateView()) {
			updateView();
		}
	}
}

void SI::SpaceInvaders::updateController() {
	controller->removeEntities();
	controller->update();
}

void SI::SpaceInvaders::updateModel() {
	model->update();
	auto entities = model->getNewModels();
	for (const auto& entity: entities) {
		addEntity(entity);
	}
	model->removeEntities();
}

void SI::SpaceInvaders::updateView() {
	view->removeEntities();
	view->update();
}

std::weak_ptr<SI::model::Entity> SI::SpaceInvaders::addEntity(const std::shared_ptr<model::Entity>& entityModel) {
	std::shared_ptr<view::Entity> entityView;
	std::shared_ptr<controller::Entity> entityController;

	if (auto bullet = std::dynamic_pointer_cast<model::Bullet>(entityModel)) {
		entityView = std::make_shared<view::Bullet>(bullet, view->getWindow());
	} else if (auto explosion = std::dynamic_pointer_cast<model::Explosion>(entityModel)) {
		entityView = std::make_shared<view::Explosion>(explosion, view->getWindow());
	} else if (auto enemy = std::dynamic_pointer_cast<model::Enemy>(entityModel)) {
		auto castedView = std::make_shared<view::Enemy>(enemy, view->getWindow());
		entityView = castedView;
		entityController = std::make_shared<controller::Enemy>(enemy, castedView);
	} else if (auto wave = std::dynamic_pointer_cast<model::Wave>(entityModel)) {
		entityView = std::make_shared<view::Wave>(wave, view->getWindow());
	} else if (auto shield = std::dynamic_pointer_cast<model::Shield>(entityModel)) {
		entityView = std::make_shared<view::Shield>(shield, view->getWindow());
	} else if (auto player = std::dynamic_pointer_cast<model::Player>(entityModel)) {
		auto castedView = std::make_shared<view::Player>(player, view->getWindow());
		entityView = castedView;
		entityController = std::make_shared<controller::Player>(player, castedView);
	} else {
		throw std::runtime_error("Entity instance is not supported");
	}

	entityModel->addObserver(entityView);

	model->addEntity(entityModel);
	view->addEntity(entityView);
	controller->addEntity(entityController);

	return entityModel;
}
