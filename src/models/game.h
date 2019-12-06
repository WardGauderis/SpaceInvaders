//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H

#include "world.h"

namespace SI::model {

	class Game : public Model {
	public:
		Game();

		void update() final;

		const std::shared_ptr<model::World>& getWorld() const;

	private:
		std::shared_ptr<model::World> world;
	};

}

#endif //SPACEINVADERS_GAMEMODEL_H
