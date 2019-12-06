//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDVIEW_H
#define SPACEINVADERS_WORLDVIEW_H

#include "entity.h"
#include "../models/world.h"

namespace SI::view {

	class World : public Entity {
	public:
		World(const std::shared_ptr<model::World>& model);

		void notify() override;

		void update() override;

		void addEntity(const std::shared_ptr<Entity>& entity);

		void removeEntity(const std::shared_ptr<Entity>& entity);

		~World() final = default;

	private:
		std::unordered_set<std::shared_ptr<Entity>> entities;
	};

}

#endif //SPACEINVADERS_WORLDVIEW_H
