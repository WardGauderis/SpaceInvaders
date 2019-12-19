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
		          unsigned int lives, float bulletSpeed, bool team);

		void update() override;

		[[nodiscard]] unsigned int getLives() const;

		void setLives(unsigned int lives);

		virtual unsigned int loseLive();

		[[nodiscard]] float getBulletSpeed() const;

		void setBulletSpeed(float bulletSpeed);

		~SpaceShip() override = default;

	protected:
		bool shoot(bool team);

	private:
		unsigned int lives;
		float bulletSpeed;
	};

}

#endif //SPACEINVADERS_SPACESHIPMODEL_H
