//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_BULLETMODEL_H
#define SPACEINVADERS_BULLETMODEL_H

#include "physicalEntity.h"

namespace SI::model {

	class Bullet : public PhysicalEntity {
	public:
		Bullet(const utils::Vector& velocity, bool team);

		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) override;

		~Bullet() final = default;

	private:
		void onWallCollision(utils::Vector wall) override;
	};

}

#endif //SPACEINVADERS_BULLETMODEL_H
