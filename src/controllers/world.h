//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDCONTROLLER_H
#define SPACEINVADERS_WORLDCONTROLLER_H

#include "player.h"

namespace SI::controller {

	class World : public Entity {
	public:
		World(const std::shared_ptr<view::World>& view, const std::shared_ptr<model::World>& model);

		void handleInput() final;

		void addEntity(const std::shared_ptr<Entity>& entity);

		void removeEntity(const std::shared_ptr<Entity>& entity);

	private:
		std::unordered_set<std::shared_ptr<Entity>> entities;
	};

}

#endif //SPACEINVADERS_WORLDCONTROLLER_H
