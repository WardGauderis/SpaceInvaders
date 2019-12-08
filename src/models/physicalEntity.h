//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_PHYSICALENTITYMODEL_H
#define SPACEINVADERS_PHYSICALENTITYMODEL_H

#include "entity.h"
#include "../utils/vector.h"

namespace SI::model {

	class PhysicalEntity : public Entity {
	public:
		PhysicalEntity() = default;

		void update() override;

		void move();

		virtual void action(SpaceInvaders& game);

		void addVelocity(const utils::Vector& vel);

		[[nodiscard]] const utils::Vector& getPosition() const;

		void setPosition(const utils::Vector& position);

		[[nodiscard]] const utils::Vector& getVelocity() const;

		void setVelocity(const utils::Vector& velocity);

		[[nodiscard]] const utils::Vector& getSize() const;

		void setSize(const utils::Vector& size);

		virtual void onCollision(const std::shared_ptr<PhysicalEntity>& entity) = 0;

		~PhysicalEntity() override = default;

		static bool
		collides(const std::shared_ptr<PhysicalEntity>& entity0, const std::shared_ptr<PhysicalEntity>& entity1);

	protected:
		utils::Vector size;
		utils::Vector position;
		utils::Vector velocity;

	};

}

#endif //SPACEINVADERS_PHYSICALENTITYMODEL_H
