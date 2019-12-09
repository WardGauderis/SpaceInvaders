//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include "../utils/observer.h"

namespace SI {
	class SpaceInvaders;
}

namespace SI::model {

	class Entity : public utils::Subject {
	public:
		Entity();

		virtual void update() = 0;

		virtual ~Entity() = default;

	private:
		bool alive;
	};

}

#endif //SPACEINVADERS_ENTITYMODEL_H
