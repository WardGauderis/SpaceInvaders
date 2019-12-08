//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_PHYSICALENTITYCONTROLLER_H
#define SPACEINVADERS_PHYSICALENTITYCONTROLLER_H

#include "entity.h"
#include "../views/physicalEntity.h"

namespace SI::controller {

	class PhysicalEntity : public Entity {
	public:
		PhysicalEntity(std::shared_ptr<model::PhysicalEntity> model,
		               std::shared_ptr<view::PhysicalEntity> view);

		~PhysicalEntity() override = default;

	protected:
		std::shared_ptr<model::PhysicalEntity> model;
		std::shared_ptr<view::PhysicalEntity> view;
	};

}

#endif //SPACEINVADERS_PHYSICALENTITYCONTROLLER_H
