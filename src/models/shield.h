//
// Created by ward on 12/15/19.
//

#ifndef SPACEINVADERS_SHIELDMODEL_H
#define SPACEINVADERS_SHIELDMODEL_H

#include "physicalEntity.h"

namespace SI::model {

	class Shield : public PhysicalEntity {
	public:
		explicit Shield(const utils::Vector& position);

		void update() final;

		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) final;

		~Shield() final = default;
	};

}

#endif //SPACEINVADERS_SHIELDMODEL_H
