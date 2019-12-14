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
		          unsigned int lives);

		void update() override;

		unsigned int getLives() const;

		void setLives(unsigned int lives);

		unsigned int loseLive();

		~SpaceShip() override = default;

	protected:
		bool shoot(bool team);

	private:
		unsigned int lives;
	};

}

#endif //SPACEINVADERS_SPACESHIPMODEL_H
