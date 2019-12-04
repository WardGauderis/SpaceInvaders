//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include "controller.h"
#include "../models/entity.h"

namespace SI::controller {

	class Entity : public Controller {
	public:
		Entity(const std::shared_ptr<view::View>& view, const std::shared_ptr<model::Entity>& model);

	protected:
		std::shared_ptr<model::Entity> model;

	};

}

#endif //SPACEINVADERS_ENTITYCONTROLLER_H
