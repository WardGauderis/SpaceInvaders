//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_PHYSICALENTITYVIEW_H
#define SPACEINVADERS_PHYSICALENTITYVIEW_H

#include "entity.h"
#include "../models/physicalEntity.h"

namespace SI::view {

	class PhysicalEntity : public Entity {
	public:
		PhysicalEntity(std::shared_ptr<model::PhysicalEntity>  model, const std::shared_ptr<sf::RenderWindow>& window);

		void notify() override;

		void update() override;

		~PhysicalEntity() override = default;

	protected:
		std::shared_ptr<model::PhysicalEntity> model;
	};

}

#endif //SPACEINVADERS_PHYSICALENTITYVIEW_H
