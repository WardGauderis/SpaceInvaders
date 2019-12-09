//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_SPACEINVADERS_H
#define SPACEINVADERS_SPACEINVADERS_H

#include "controllers/world.h"
#include "entities.h"

namespace SI {

	class SpaceInvaders {
	public:
		SpaceInvaders();

		void eventLoop();

		template<class Entity>
		auto addEntity() -> std::shared_ptr<typename Entity::Model>;

	private:
		std::shared_ptr<model::World> model;
		std::shared_ptr<view::World> view;
		std::shared_ptr<controller::World> controller;

		bool running;

		void updateController();

		void updateModel();

		void updateView();
	};

}


#endif //SPACEINVADERS_SPACEINVADERS_H
