//
// Created by ward on 11/19/19.
//

#include "spaceInvaders.h"
#include "utils/stopWatch.h"

SI::SpaceInvaders::SpaceInvaders() : model(std::make_shared<model::World>()),
                                     view(std::make_shared<view::World>(model)),
                                     controller(std::make_shared<controller::World>(model, view)),
                                     running(true) {
	addEntity<Player>();
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

	controller->update(*this);
}

void SI::SpaceInvaders::updateModel() {
	model->update();
}

void SI::SpaceInvaders::updateView() {
	view->update();
}

template<class Entity>
auto SI::SpaceInvaders::addEntity() -> std::shared_ptr<typename Entity::Model> {
	auto entityModel = std::make_shared<typename Entity::Model>();
	auto entityView = std::make_shared<typename Entity::View>(entityModel, view->getWindow());
	auto entityController = std::make_shared<typename Entity::Controller>(entityModel, entityView);

	entityModel->registerObserver(entityView);

	model->addEntity(entityModel);
	view->addEntity(entityView);
	controller->addEntity(entityController);

	return entityModel;
}

template std::shared_ptr<SI::Player::Model> SI::SpaceInvaders::addEntity<SI::Player>();
template std::shared_ptr<SI::Bullet::Model> SI::SpaceInvaders::addEntity<SI::Bullet>();