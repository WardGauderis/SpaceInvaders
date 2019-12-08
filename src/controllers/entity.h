//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

namespace SI {
	class SpaceInvaders;
}

namespace SI::controller {

	class Entity {
	public:
		Entity() = default;

		virtual void update(SpaceInvaders& game) = 0;

		virtual ~Entity() = default;

	};

}

#endif //SPACEINVADERS_ENTITYCONTROLLER_H
