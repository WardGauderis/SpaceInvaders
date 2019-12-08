//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_BULLETMODEL_H
#define SPACEINVADERS_BULLETMODEL_H

#include "physicalEntity.h"

namespace SI::model {

	class Bullet : public PhysicalEntity {
	public:
		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) final;

		~Bullet() final = default;
	};

}

#endif //SPACEINVADERS_BULLETMODEL_H
