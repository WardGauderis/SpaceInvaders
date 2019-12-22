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

		enum class State{
			running,
			pause,
			victory,
			defeat,
			start
		};

		World();

		void reset();

		void update() final;

		void addEntity(const std::shared_ptr<Entity>& entity);

		std::vector<std::shared_ptr<Entity>> getNewModels() override;

		void removeEntities();

		const std::weak_ptr<model::Player>& getPlayer() const;

		const std::weak_ptr<model::Wave>& getWave() const;

		State getState() const;

		void setState(State state);

		~World() final = default;

	private:
		std::unordered_set<std::shared_ptr<Entity>> entities;
		std::unordered_set<std::shared_ptr<PhysicalEntity>> physicalEntities;

		std::weak_ptr<model::Player> player;
		std::weak_ptr<model::Wave> wave;

		State state;
	};

}

#endif //SPACEINVADERS_WORLDMODEL_H
