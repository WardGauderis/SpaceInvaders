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
		World(const std::shared_ptr<view::View>& view, const std::shared_ptr<model::Entity>& model);

		void handleInput() final;

	private:
		std::shared_ptr<Player> player;

	};

}

#endif //SPACEINVADERS_WORLDCONTROLLER_H
