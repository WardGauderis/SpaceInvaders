//
// Created by ward on 12/16/19.
//

#ifndef SPACEINVADERS_EXPLOSIONPARTICLEMODEL_H
#define SPACEINVADERS_EXPLOSIONPARTICLEMODEL_H

#include "physicalEntity.h"
#include "../utils/stopWatch.h"

namespace SI::model {

	class ExplosionParticle : public PhysicalEntity {
	public:
		ExplosionParticle(const utils::Vector& size, const utils::Vector& position, const utils::Vector& velocity);

		void update() final;

		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) override;

		~ExplosionParticle() final = default;

	private:
		utils::Timer timer;

		void move() final;

		void onWallCollision(utils::Vector wall) final;
	};

}

#endif //SPACEINVADERS_EXPLOSIONPARTICLEMODEL_H
