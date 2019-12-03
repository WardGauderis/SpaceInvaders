//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDCONTROLLER_H
#define SPACEINVADERS_WORLDCONTROLLER_H

#include "entity.h"
#include "player.h"

namespace SI::controller {

	class World : public Entity {
	public:
		virtual void handleInput() final;

	private:
		Player player;

	};

}

#endif //SPACEINVADERS_WORLDCONTROLLER_H
