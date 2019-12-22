//
// Created by ward on 12/19/19.
//

#ifndef SPACEINVADERS_SHIELDVIEW_H
#define SPACEINVADERS_SHIELDVIEW_H

#include "physicalEntity.h"
#include "../models/shield.h"

namespace SI::view {

	class Shield : public PhysicalEntity {
	public:
		Shield(const std::weak_ptr<model::Shield>& model, const std::shared_ptr<sf::RenderWindow>& window);

		void notify() override;

		void update() override;

		int drawOrder() final;
	};

}

#endif //SPACEINVADERS_SHIELDVIEW_H
