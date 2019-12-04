//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAMEVIEW_H
#define SPACEINVADERS_GAMEVIEW_H

#include "view.h"
#include "world.h"
#include "../models/game.h"

namespace SI::view {

	class Game : public View {
	public:
		Game(const std::shared_ptr<model::Game>& model);

		void draw() final;

		void notify() final;

		const std::shared_ptr<World>& getWorld() const;

	private:
		std::shared_ptr<World> world;

	};

}

#endif //SPACEINVADERS_GAMEVIEW_H
