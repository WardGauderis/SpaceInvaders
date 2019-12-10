//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDCONTROLLER_H
#define SPACEINVADERS_WORLDCONTROLLER_H

#include "player.h"
#include "../views/world.h"

namespace SI::controller {

	class World : public Entity {
	public:
		World(std::shared_ptr<model::World>  model, std::shared_ptr<view::World>  view);

		void update(SpaceInvaders& game) final;

		void addEntity(const std::shared_ptr<Entity>& entity);

		void removeEntities();

		~World() final = default;

	private:
		std::shared_ptr<model::World> model;
		std::shared_ptr<view::World> view;
		std::unordered_set<std::shared_ptr<Entity>> entities;

	};

}

#endif //SPACEINVADERS_WORLDCONTROLLER_H
