//
// Created by ward on 12/16/19.
//

#include "explosionParticle.h"

SI::controller::ExplosionParticle::ExplosionParticle(const std::weak_ptr<model::ExplosionParticle>& model,
                                                     const std::weak_ptr<view::ExplosionParticle>& view)
		: PhysicalEntity(model, view) {}
