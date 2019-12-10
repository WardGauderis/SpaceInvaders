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
		Bullet(const std::weak_ptr<model::Bullet>& model, const std::weak_ptr<view::Bullet>& view);

		~Bullet() final = default;
	};

}


#endif //SPACEINVADERS_BULLETCONTROLLER_H
