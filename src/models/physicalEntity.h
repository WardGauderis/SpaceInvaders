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
		PhysicalEntity(float drag, const utils::Vector& size, const utils::Vector& position,
		               const utils::Vector& velocity);

		void update() override;

		void addVelocity(const utils::Vector& vel);

		[[nodiscard]] const utils::Vector& getPosition() const;

		void setPosition(const utils::Vector& position);

		[[nodiscard]] const utils::Vector& getVelocity() const;

		void setVelocity(const utils::Vector& velocity);

		[[nodiscard]] const utils::Vector& getSize() const;

		void setSize(const utils::Vector& size);

		virtual void onCollision(const std::shared_ptr<PhysicalEntity>& entity);

		~PhysicalEntity() override = default;

		static bool
		detectCollision(const std::shared_ptr<PhysicalEntity>& entity0, const std::shared_ptr<PhysicalEntity>& entity1);

	protected:
		float drag;
		utils::Vector size;
		utils::Vector position;
		utils::Vector velocity;

		virtual void move();

		utils::Vector detectWallCollision();

		virtual void onWallCollision(utils::Vector wall);

		void deleteThis() override;

	};

}

#endif //SPACEINVADERS_PHYSICALENTITYMODEL_H
