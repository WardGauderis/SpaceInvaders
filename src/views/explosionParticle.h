//
// Created by ward on 12/16/19.
//

#ifndef SPACEINVADERS_EXPLOSIONPARTICLEVIEW_H
#define SPACEINVADERS_EXPLOSIONPARTICLEVIEW_H

#include "physicalEntity.h"
#include "../models/explosionParticle.h"

namespace SI::view {

	class ExplosionParticle : public PhysicalEntity {
	public:
		ExplosionParticle(const std::weak_ptr<model::ExplosionParticle>& model,
		                  const std::shared_ptr<sf::RenderWindow>& window);

		int drawOrder() final;

		~ExplosionParticle() final = default;
	};

}

#endif //SPACEINVADERS_EXPLOSIONPARTICLEVIEW_H
