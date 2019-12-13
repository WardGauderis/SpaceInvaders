//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_BULLETMODEL_H
#define SPACEINVADERS_BULLETMODEL_H

#include "physicalEntity.h"

namespace SI::model {

	class Bullet : public PhysicalEntity {
	public:
		Bullet(bool playerTeam);

		void onCollision(const std::shared_ptr<PhysicalEntity>& entity) override;

		bool getTeam() const;

		~Bullet() final = default;

	private:
		void onWallCollision(utils::Vector wall) override;

		bool playerTeam;
	};

}

#endif //SPACEINVADERS_BULLETMODEL_H
