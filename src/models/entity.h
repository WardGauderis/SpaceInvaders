//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include "../utils/vector.h"
#include "../utils/observer.h"

namespace SI::model {

	class Entity : public utils::Subject {
	public:
		Entity() = default;

		virtual void update() = 0;

		void move();

		void addAcceleration(const utils::Vector& acc);

		~Entity() = default;

	private:
		utils::Vector position;
		utils::Vector velocity;
		utils::Vector acceleration;
	};

}

#endif //SPACEINVADERS_ENTITYMODEL_H
