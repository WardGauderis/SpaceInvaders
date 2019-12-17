//
// Created by ward on 12/16/19.
//

#ifndef SPACEINVADERS_EXPLOSIONPARTICLECONTROLLER_H
#define SPACEINVADERS_EXPLOSIONPARTICLECONTROLLER_H

#include "physicalEntity.h"
#include "../models/explosionParticle.h"
#include "../views/explosionParticle.h"

namespace SI::controller {

	class ExplosionParticle : public PhysicalEntity {
	public:
		ExplosionParticle(const std::weak_ptr<model::ExplosionParticle>& model,
		                  const std::weak_ptr<view::ExplosionParticle>& view);

		~ExplosionParticle() final = default;
	};

}

#endif //SPACEINVADERS_EXPLOSIONPARTICLECONTROLLER_H
