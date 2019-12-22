//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_SPACEINVADERS_H
#define SPACEINVADERS_SPACEINVADERS_H

#include "controllers/world.h"

namespace SI {

	class SpaceInvaders {
	public:
		SpaceInvaders();

		void eventLoop();

	private:
		std::shared_ptr<model::World> model;
		std::shared_ptr<view::World> view;
		std::shared_ptr<controller::World> controller;

		void updateController();

		void updateModel();

		void updateView();

		std::weak_ptr<model::Entity> addEntity(const std::shared_ptr<model::Entity>& entityModel);
	};

}


#endif //SPACEINVADERS_SPACEINVADERS_H
