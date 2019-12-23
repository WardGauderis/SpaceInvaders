//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDMODEL_H
#define SPACEINVADERS_WORLDMODEL_H

#include <unordered_set>

#include "player.h"
#include "wave.h"

namespace SI::model {
	/**
	 * model class for the world
	 */
	class World : public Entity {
	public:
		/**
		 * internal states of the world
		 */
		enum class State {
			running,
			pause,
			victory,
			defeat,
			start
		};

		/**
		 * default constructor
		 */
		World();

		/**
		 * reset the world
		 */
		void reset();

		/**
		 * function that is called every game tick
		 * update all the models, handle collision and adjust state
		 */
		void update() final;

		/**
		 * add an entity to the world
		 */
		void addEntity(const std::shared_ptr<Entity>& entity);

		/**
		 * poll whether the object wants to add new models to the world
		 * polls all the entities
		 * @return vector of models
		 */
		std::vector<std::shared_ptr<Entity>> getNewModels() override;

		/**
		 * remove an entity from the world
		 */
		void removeEntities();

		/**
		 * get the player
		 * @return player
		 */
		const std::weak_ptr<model::Player>& getPlayer() const;

		/**
		 * get the wave
		 * @return return wave
		 */
		const std::weak_ptr<model::Wave>& getWave() const;

		/**
		 * get the state
		 * @return state
		 */
		State getState() const;

		/**
		 * set the state
		 * @param state new state
		 */
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
