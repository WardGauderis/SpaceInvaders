//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include <memory>
#include "../views/entity.h"

namespace SI::controller {

	class Entity {
	public:
		Entity(std::shared_ptr<model::Entity> model, std::shared_ptr<view::Entity> view);

		virtual void update() = 0;

		virtual ~Entity() = default;

	protected:
		std::shared_ptr<model::Entity> model;
		std::shared_ptr<view::Entity> view;

	};

}

#endif //SPACEINVADERS_ENTITYCONTROLLER_H
