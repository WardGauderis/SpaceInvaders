//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_BULLETMODEL_H
#define SPACEINVADERS_BULLETMODEL_H

#include "physicalEntity.h"

namespace SI::model {

	class Bullet : public PhysicalEntity {
	public:
		Bullet();

		~Bullet() final = default;
	};

}

#endif //SPACEINVADERS_BULLETMODEL_H
