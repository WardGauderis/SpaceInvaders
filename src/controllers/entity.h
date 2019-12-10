//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include <memory>
#include "../views/entity.h"

namespace SI {
	class SpaceInvaders;
}

namespace SI::controller {

	class Entity {
	public:
		Entity();

		virtual void update(SpaceInvaders& game) = 0;

		[[nodiscard]] bool mayDeleteThis() const;

		virtual ~Entity() = default;

	protected:
		void deleteThis();

	private:
		bool mustDelete;
	};

}

#endif //SPACEINVADERS_ENTITYCONTROLLER_H
