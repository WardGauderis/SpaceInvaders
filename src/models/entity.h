//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include "model.h"
#include "../utils/vector.h"

namespace SI::model {

	class Entity : public Model {
	public:
		void move();

	private:
		utils::Vector position;
		utils::Vector velocity;
		utils::Vector acceleration;
	};

}

#endif //SPACEINVADERS_ENTITYMODEL_H
