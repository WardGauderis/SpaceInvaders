//
// Created by ward on 12/19/19.
//

#ifndef SPACEINVADERS_EXPLOSIONMODEL_H
#define SPACEINVADERS_EXPLOSIONMODEL_H

#include <random>

#include "physicalEntity.h"
#include "../utils/vector.h"
#include "../utils/stopWatch.h"

namespace SI::model {

	class Explosion : public Entity {
	public:

		class ExplosionParticle {
		public:
			ExplosionParticle(utils::Vector position, utils::Vector velocity);

			[[nodiscard]] const utils::Vector& getPosition() const;

			void update(utils::Vector size);

		private:
			utils::Vector position;
			utils::Vector velocity;

			static float drag;
			static std::normal_distribution<> distribution;

			[[nodiscard]] utils::Vector detectWallCollision(utils::Vector size) const;

			void onWallCollision(utils::Vector wall, utils::Vector size);
		};

		Explosion(const PhysicalEntity& origin);

		void update() final;

		[[nodiscard]] const utils::Vector& getSize() const;

		[[nodiscard]] const utils::Timer& getTimer() const;

		[[nodiscard]] bool getTeam() const;

		[[nodiscard]] const std::vector<ExplosionParticle>& getParticles() const;

		~Explosion() final = default;

	private:
		std::vector<ExplosionParticle> particles;
		utils::Vector size;
		utils::Timer timer;
		bool team;

		static std::default_random_engine generator;
		static std::normal_distribution<> distribution;
	};

}

#endif //SPACEINVADERS_EXPLOSIONMODEL_H
