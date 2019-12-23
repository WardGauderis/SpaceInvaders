//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_BULLETMODEL_H
#define SPACEINVADERS_BULLETMODEL_H

#include "physicalEntity.h"

namespace SI::model {
	/**
	 * model class for bullets
	 */
	class Bullet : public PhysicalEntity {
	public:
		/**
		 * construct with velocity and team
		 * @param velocity vector
		 * @param team true if friendly
		 */
		Bullet(const utils::Vector& velocity, bool team);

		/**
		 * handle collision with entity
		 */
		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) final;

		~Bullet() final = default;

	private:
		/**
		 * handle wall collision
		 * @param wall collision position
		 */
		void onWallCollision(utils::Vector wall) final;
	};

}

#endif //SPACEINVADERS_BULLETMODEL_H
