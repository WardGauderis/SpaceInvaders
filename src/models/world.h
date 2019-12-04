//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDMODEL_H
#define SPACEINVADERS_WORLDMODEL_H

#include "entity.h"
#include "player.h"

namespace SI::model {

	class World : public Entity {
	public:
		void update() final;

	private:
		Player player;
	};

}

#endif //SPACEINVADERS_WORLDMODEL_H
