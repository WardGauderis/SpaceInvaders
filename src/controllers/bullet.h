//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_BULLETCONTROLLER_H
#define SPACEINVADERS_BULLETCONTROLLER_H

#include "physicalEntity.h"
#include "../views/bullet.h"

namespace SI::controller {

	class Bullet: public PhysicalEntity {
	public:
		Bullet(const std::shared_ptr<model::Bullet>& model, const std::shared_ptr<view::Bullet>& view);

		void update(SpaceInvaders& game) override;

		~Bullet() final = default;
	};

}


#endif //SPACEINVADERS_BULLETCONTROLLER_H
