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
		std::vector<std::shared_ptr<Entity>> models;
	};

}

#endif //SPACEINVADERS_WORLDMODEL_H
