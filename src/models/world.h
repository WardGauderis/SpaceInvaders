//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDMODEL_H
#define SPACEINVADERS_WORLDMODEL_H

#include <unordered_set>

#include "player.h"

namespace SI::model {

	class World : public Entity {
	public:
		World() = default;

		void update() final;

		void addEntity(const std::shared_ptr<Entity>& entity);

		void removeEntity(const std::shared_ptr<Entity>& entity);

		~World() final = default;

	private:
		std::unordered_set<std::shared_ptr<Entity>> entities;
	};

}

#endif //SPACEINVADERS_WORLDMODEL_H
