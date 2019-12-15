//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_SPACESHIPMODEL_H
#define SPACEINVADERS_SPACESHIPMODEL_H

#include "physicalEntity.h"

namespace SI::model {

	class SpaceShip : public PhysicalEntity {
	public:
		SpaceShip(float drag, const utils::Vector& size, const utils::Vector& position, const utils::Vector& velocity,
		          const unsigned int lives, const float bulletSpeed);

		void update() override;

		unsigned int getLives() const;

		void setLives(unsigned int lives);

		unsigned int loseLive();

		float getBulletSpeed() const;

		void setBulletSpeed(float bulletSpeed);

		~SpaceShip() override = default;

	protected:
		bool shoot(const bool team);

	private:
		unsigned int lives;
		float bulletSpeed;
	};

}

#endif //SPACEINVADERS_SPACESHIPMODEL_H
