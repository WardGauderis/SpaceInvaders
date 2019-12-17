//
// Created by ward on 11/19/19.
//

#include "spaceInvaders.h"
#include "utils/stopWatch.h"
#include "controllers/wave.h"
#include "controllers/bullet.h"
#include "views/display.h"
#include "models/explosionParticle.h"
#include "views/explosionParticle.h"
#include "controllers/explosionParticle.h"

SI::SpaceInvaders::SpaceInvaders() : model(std::make_shared<model::World>()),
                                     view(std::make_shared<view::World>(model)),
                                     controller(std::make_shared<controller::World>(model, view)),
                                     running(true) {
	auto newPlayer = std::make_shared<model::Player>();
	auto newWave = std::make_shared<model::Wave>();
	auto newDisplay = std::make_shared<view::Display>(view->getWindow(), newPlayer, newWave);
	newPlayer->addObserver(newDisplay);
	newWave->addObserver(newDisplay);
	view->addEntity(newDisplay);
	player = addEntity(newPlayer);
	wave = addEntity(newWave);
}

void SI::SpaceInvaders::eventLoop() {
	while (running) {
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
	utils::Event event{};
	while (view->pollEvent(event)) {
		switch (event.type) {
			case utils::Event::Closed:
				running = false;
				break;
		}
	}

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
	checkIfFinished();
}

void SI::SpaceInvaders::updateView() {
	view->removeEntities();
	view->update();
}

std::weak_ptr<SI::model::Entity> SI::SpaceInvaders::addEntity(const std::shared_ptr<model::Entity>& entityModel) {
	std::shared_ptr<view::Entity> entityView;
	std::shared_ptr<controller::Entity> entityController;

	if (auto bullet = std::dynamic_pointer_cast<model::Bullet>(entityModel)) {
		auto castedView = std::make_shared<view::Bullet>(bullet, view->getWindow());
		entityView = castedView;
		entityController = std::make_shared<controller::Bullet>(bullet, castedView);
	} else if (auto enemy = std::dynamic_pointer_cast<model::Enemy>(entityModel)) {
		auto castedView = std::make_shared<view::Enemy>(enemy, view->getWindow());
		entityView = castedView;
		entityController = std::make_shared<controller::Enemy>(enemy, castedView);
	} else if (auto explosionParticle = std::dynamic_pointer_cast<model::ExplosionParticle>(entityModel)) {
		auto castedView = std::make_shared<view::ExplosionParticle>(explosionParticle, view->getWindow());
		entityView = castedView;
		entityController = std::make_shared<controller::ExplosionParticle>(explosionParticle, castedView);
	} else if (auto wave = std::dynamic_pointer_cast<model::Wave>(entityModel)) {
		auto castedView = std::make_shared<view::Wave>(wave, view->getWindow());
		entityView = castedView;
		entityController = std::make_shared<controller::Wave>(wave, castedView);
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

bool SI::SpaceInvaders::checkIfFinished() {
	running = running && player.lock() && wave.lock();
//	running = true;
	return running;
}
