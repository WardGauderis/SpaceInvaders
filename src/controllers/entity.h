//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include "controller.h"

namespace SI::controller {

	class Entity : public Controller {
	public:
		Entity(std::shared_ptr<view::Entity>  view, std::shared_ptr<model::Entity>  model);

	protected:
		std::shared_ptr<model::Entity> model;
		std::shared_ptr<view::Entity> view;

	};

}

#endif //SPACEINVADERS_ENTITYCONTROLLER_H
