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

		void reset();

		void update() final;

		void addEntity(const std::shared_ptr<Entity>& entity);

		void removeEntities();

		bool isRunning() const;

		~World() final = default;

	private:
		std::shared_ptr<model::World> model;
		std::shared_ptr<view::World> view;
		std::unordered_set<std::shared_ptr<Entity>> entities;

		bool running;

	};

}

#endif //SPACEINVADERS_WORLDCONTROLLER_H
