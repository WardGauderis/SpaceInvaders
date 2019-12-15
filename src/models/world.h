//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDMODEL_H
#define SPACEINVADERS_WORLDMODEL_H

#include <unordered_set>

#include "player.h"
#include "wave.h"

namespace SI::model {

	class World : public Entity {
	public:
		World() = default;

		void update() final;

		void addEntity(const std::shared_ptr<Entity>& entity);

		std::vector<std::shared_ptr<Entity>> getNewModels() override;

		void removeEntities();

		~World() final = default;

	private:
		std::unordered_set<std::shared_ptr<Entity>> entities;
		std::unordered_set<std::shared_ptr<PhysicalEntity>> physicalEntities;

	};

}

#endif //SPACEINVADERS_WORLDMODEL_H
