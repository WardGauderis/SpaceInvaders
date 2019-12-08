//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDVIEW_H
#define SPACEINVADERS_WORLDVIEW_H

#include <set>

#include "entity.h"
#include "../models/world.h"

namespace SI::view {

	class World : public Entity {
	public:
		World(std::shared_ptr<model::World> model);

		void notify() final;

		void update() final;

		void addEntity(const std::shared_ptr<Entity>& entity);

		void removeEntity(const std::shared_ptr<Entity>& entity);

		std::shared_ptr<sf::RenderWindow> getWindow() const;

		~World() final = default;

	private:
		std::shared_ptr<model::World> model;
		std::set<std::shared_ptr<Entity>, std::function<bool(const std::shared_ptr<SI::view::Entity>&,
		                                                     const std::shared_ptr<SI::view::Entity>&)>> entities;
	};

}

#endif //SPACEINVADERS_WORLDVIEW_H
